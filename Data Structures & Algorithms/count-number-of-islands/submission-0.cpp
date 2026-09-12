class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int result =0;  
        int ROWS = grid.size();
        int COLS = grid[0].size();
        for(int i =0; i< ROWS; i++)
        {
            for(int j =0; j<COLS; j++)
            {
                if(grid[i][j]=='1')
                {
                    
                    dfs(grid, i,j);
                    result++;
                }
            }
        }

        return result;
    }

    void dfs(vector<vector<char>> & grid, int i, int j)
    {
       if (i < 0 || i >= (int)grid.size() || j < 0 || j >= (int)grid[0].size())
    {
        return; // out of bounds, check this BEFORE touching grid[i][j]
    }
    if (grid[i][j] == '0' || grid[i][j] == '#')
    {
        return; // water or already visited
    }

        grid[i][j] = '#';
        // visited

        dfs(grid, i+1,j);
        dfs(grid, i,j+1);
        dfs(grid, i-1,j);
        dfs(grid, i,j-1);
    }
};
