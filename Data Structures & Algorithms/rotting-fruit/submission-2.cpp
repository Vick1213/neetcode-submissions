class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int i=0;

        int rows = grid.size();
        int cols = grid[0].size();
        
        queue<pair<int,int>> q;
        set<pair<int,int>>found_fresh;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        
        for(auto & rows: grid)
        {
            int j=0;
            for(auto & item: rows)
            {
                if(item==2)
                {
                    q.push({i,j});
                    visited[i][j] =true;
                }
                if(item == 1)
                {
                    found_fresh.insert({i,j});
                }
                j++;
            }
            i++;
        }

       auto addCell = [&](int r, int c) -> bool {
    if (r < 0 || r >= rows || c < 0 || c >= cols || visited[r][c] || grid[r][c] == 0) {
        return false;
    }
    grid[r][c] = 2;
    visited[r][c] = true;
    q.push({r, c});
    return true;
};

        int minutes =0;

       while (!q.empty()) {
    int size = q.size();
    bool spread = false;
    for (int l = 0; l < size; l++) {
        auto [x, y] = q.front();
        q.pop();
        // addCell already checks bounds/visited/wall; have it report success
        spread |= addCell(x+1, y);
        spread |= addCell(x-1, y);
        spread |= addCell(x, y+1);
        spread |= addCell(x, y-1);
    }
    if (spread) minutes++;
}

        for(const auto & fresh:found_fresh)
        {
            if(grid[fresh.first][fresh.second] ==1)
            {
                return -1;
            }
        }

        return minutes;

        
    }
};
