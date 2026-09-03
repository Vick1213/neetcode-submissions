class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        set<pair<int,int>> pathset;
        for (int x = 0; x < rows; x++) {
            for (int y = 0; y < cols; y++) {
                if (board[x][y] == word[0] && recurr(board, word, x, y, 0, pathset))
                    return true;
            }
        }
        return false;
    }

    bool recurr(vector<vector<char>>& board, string& word, int i, int j, int place, set<pair<int,int>>& pathset) {
        if (i < 0 || i >= (int)board.size() || j < 0 || j >= (int)board[0].size()
            || pathset.count({i, j}) || board[i][j] != word[place])
            return false;

        if (place == (int)word.size() - 1) return true;

        pathset.insert({i, j});
        bool found = recurr(board, word, i, j + 1, place + 1, pathset) ||
                     recurr(board, word, i, j - 1, place + 1, pathset) ||
                     recurr(board, word, i - 1, j, place + 1, pathset) ||
                     recurr(board, word, i + 1, j, place + 1, pathset);
        pathset.erase({i, j});

        return found;
    }
};