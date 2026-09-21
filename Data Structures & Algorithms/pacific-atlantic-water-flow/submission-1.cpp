class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {
            dfs(i, 0, heights, pacific);
            dfs(i, cols-1, heights, atlantic);
        }
        for (int i = 0; i < cols; i++) {
            dfs(0, i, heights, pacific);
            dfs(rows-1, i, heights, atlantic);
        }

        vector<vector<int>> results;
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
                if (pacific[r][c] && atlantic[r][c])
                    results.push_back({r, c});

        return results;
    }

    void dfs(int startX, int startY, vector<vector<int>>& heights, vector<vector<bool>>& ocean)
    {
        int rows = heights.size();
        int cols = heights[0].size();
        stack<pair<int,int>> st;
        st.push({startX, startY});
        ocean[startX][startY] = true;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while (!st.empty()) {
            auto [x, y] = st.top();
            st.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || nx >= rows || ny < 0 || ny >= cols) continue;
                if (ocean[nx][ny]) continue;
                if (heights[nx][ny] < heights[x][y]) continue;  // can't flow uphill from ocean's perspective
                ocean[nx][ny] = true;
                st.push({nx, ny});
            }
        }
    }
};