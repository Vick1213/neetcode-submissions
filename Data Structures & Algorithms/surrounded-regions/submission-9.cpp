class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size(), cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][cols - 1] == 'O') dfs(board, i, cols - 1);
        }

        for (int j = 0; j < cols; j++) {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[rows - 1][j] == 'O') dfs(board, rows - 1, j);
        }

        for (int x = 0; x < rows; x++) {
            for (int y = 0; y < cols; y++) {
                if (board[x][y] == 'T') board[x][y] = 'O';
                else if (board[x][y] == 'O') board[x][y] = 'X';
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O')
            return;

        board[i][j] = 'T';
        dfs(board, i + 1, j);
        dfs(board, i, j + 1);
        dfs(board, i - 1, j);
        dfs(board, i, j - 1);
    }
};