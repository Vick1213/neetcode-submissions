struct TrieNode
{
    unordered_map<char, TrieNode*> children;
    bool end_of_node = false; 
};
class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {

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
        charp->end_of_node = true;
    }
    
    bool search(string word) {
        TrieNode* charp = root;
        for(char c: word)
        {
            if(charp->children.contains(c))
            {
                charp = charp->children[c];
            }
            else
            {
                return false;
            }

        }
        return charp->end_of_node;
    }
    
    bool startsWith(string prefix) {
        TrieNode* charp = root;
        for(char c:prefix)
        {
            if(charp->children.contains(c))
            {
                charp = charp->children[c];
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
