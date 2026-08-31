class WordDictionary {
public:
    struct TrieNode{
        unordered_map<char,TrieNode*> children;
        bool end_of_word = false;
    };
    TrieNode* root;
    WordDictionary() {
         this->root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* charp = root;
        for(char c: word)
        {
            if(charp->children.contains(c))
            {
                charp = charp->children[c];
            }
            else
            {
                charp->children[c] = new TrieNode;
                charp = charp->children[c];
            }

        }
        charp->end_of_word = true;
    }
 


    bool search(string word) {
    return dfs(word, 0, root);
}

bool dfs(const string& s, int idx, TrieNode* root)
{
    for (int i = idx; i < (int)s.size(); i++)
    {
        char c = s[i];
        if (c == '.')
        {
            for (const auto& [key, node] : root->children)
                if (dfs(s, i + 1, node)) return true;
            return false;
        }
        else if (root->children.contains(c))
        {
            root = root->children[c];
        }
        else return false;
    }
    return root->end_of_word;
}
};
