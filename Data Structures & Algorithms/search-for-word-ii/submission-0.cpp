#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        string word; // non-empty once a word ends at this node
    };

    void insert(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->word = word;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& w : words) insert(root, w);

        vector<string> result;
        int rows = board.size();
        int cols = rows ? board[0].size() : 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dfs(board, i, j, root, result);
            }
        }
        return result;
    }

private:
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& result) {
        if (i < 0 || i >= (int)board.size() || j < 0 || j >= (int)board[0].size()) return;

        char c = board[i][j];
        if (c == '#' || !node->children.count(c)) return; // '#' = already used on this path

        TrieNode* next = node->children[c];
        if (!next->word.empty()) {
            result.push_back(next->word);
            next->word.clear(); // prevent duplicate matches
        }

        board[i][j] = '#'; // mark visited
        dfs(board, i + 1, j, next, result);
        dfs(board, i - 1, j, next, result);
        dfs(board, i, j + 1, next, result);
        dfs(board, i, j - 1, next, result);
        board[i][j] = c;    // backtrack
    }
};