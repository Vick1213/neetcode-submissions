class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // check left and top border wall
        // check right and bottom wall

        int rows = heights.size();
        int cols = heights[0].size();
        set<pair<int,int>> pacific;
        set<pair<int,int>> atlantic;

        for(int i =0; i<rows; i++)
        {
            //pacific.insert({i,0});

           // atlantic.insert({i,cols-1});
            dfs(i, 0, heights, pacific, heights[i][0]);
            dfs(i, cols-1, heights, atlantic, heights[i][cols-1]);
           // visited[i][cols-1] = true;
        }


         for(int i =0; i<cols; i++)
        {
           // pacific.insert({0,i});
            dfs(0, i, heights, pacific, heights[0][i]);
            dfs(rows-1, i, heights, atlantic, heights[rows-1][i]);
            //visited[rows-1][i] = true;
        }


        // dfs?


    std::vector<pair<int,int>> intersection_result;

    // Perform the intersection
    std::set_intersection(pacific.begin(), pacific.end(),
                          atlantic.begin(), atlantic.end(),
                          std::back_inserter(intersection_result));

    
        
    vector<vector<int>> results;

    for(const auto & coords:intersection_result)
    {
        vector<int> subset;
        subset.push_back(coords.first);
        subset.push_back(coords.second);
        results.push_back(subset);
    }

    return results;


    }

    void dfs(int x,int y, vector<vector<int>> & heights, set<pair<int,int>> & pacific, int currHeight)
    {
        if(x<0 || x>=heights.size() || y<0 || y>= heights[0].size() || currHeight>heights[x][y] || pacific.contains({x,y}))
        {
            return;
        }

        pacific.insert({x, y});
        // go to neighbour 
        dfs(x+1,y,heights,pacific,heights[x][y]);
        dfs(x,y+1,heights,pacific,heights[x][y]);
        dfs(x-1,y,heights,pacific,heights[x][y]);
        dfs(x,y-1,heights,pacific,heights[x][y]);
    }
};
