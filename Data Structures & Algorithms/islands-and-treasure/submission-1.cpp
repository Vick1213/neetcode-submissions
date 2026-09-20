class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    visited[i][j] = true;
                    q.push({i, j});
                }
            }
        }

        auto addCell = [&](int r, int c) {
            if (r < 0 || r >= rows || c < 0 || c >= cols || visited[r][c] || grid[r][c] == -1) {
                return;
            }
            visited[r][c] = true;
            q.push({r, c});
        };

        int dist = 0;
        while (!q.empty()) {
            int levelSize = q.size();           // snapshot the level's size
            for (int k = 0; k < levelSize; k++) {
                auto [x, y] = q.front();
                q.pop();

                grid[x][y] = dist;

                addCell(x + 1, y);
                addCell(x - 1, y);
                addCell(x, y + 1);
                addCell(x, y - 1);
            }
            dist++;                              // increment once per level, not per cell
        }
    }
};