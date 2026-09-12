class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid)  {
           
        int result =0;  
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int maxArea =0;
        for(int i =0; i< ROWS; i++)
        {
            for(int j =0; j<COLS; j++)
            {
                if(grid[i][j]==1)
                {
                    
                    maxArea = max(maxArea,dfs(grid, i,j, 0));
                    result++;
                }
            }
        }

        return maxArea;
        
    }

    int dfs(vector<vector<int>> & grid, int i, int j, int maxArea)
    {
       if (i < 0 || i >= (int)grid.size() || j < 0 || j >= (int)grid[0].size())
    {
        return maxArea; // out of bounds, check this BEFORE touching grid[i][j]
    }
    if (grid[i][j] == 0 || grid[i][j] == 7)
    {
        return maxArea; // water or already visited
    }
        maxArea++;
        grid[i][j] = 7;
        // visited

        maxArea = max(maxArea, dfs(grid, i+1,j,maxArea));
        maxArea = max(maxArea, dfs(grid, i,j+1,maxArea));
        maxArea = max(maxArea, dfs(grid, i-1,j,maxArea));
        maxArea = max(maxArea, dfs(grid, i,j-1,maxArea));

        return maxArea;
    }

};



