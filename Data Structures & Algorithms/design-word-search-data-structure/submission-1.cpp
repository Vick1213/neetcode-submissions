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
           return dfs(word, root);
    }


    bool dfs(string s, TrieNode*root)
    {
        int i=0;
        for(char c: s)
        {
            if(root->children.contains(c))
            {
                root = root->children[c];
            }
            else if( c =='.')
            {
               for (const auto& [key, node] : root->children)
            {
                if (dfs(s.substr(i + 1), node)) return true;
            }
            return false; 
            }
            else
            {
                return false;
            }
            i++;
        }
          return root->end_of_word;
    }
};
