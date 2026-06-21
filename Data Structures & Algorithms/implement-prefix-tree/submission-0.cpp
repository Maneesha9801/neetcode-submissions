class TrieNode {
    public:
        TrieNode* children[26];
        bool endOfWord;

        TrieNode(){
            for (int i = 0; i < 26 ; i++){
                children[i] = nullptr;
            }
            endOfWord = false;
        }
};

class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() { 
            root = new TrieNode();
        }
    
    void insert(string word) {
        TrieNode *cur = root;
        for (char c : word){
            int i = c - 'a';
            if (cur->children[i] == nullptr){
                cur->children[i] = new TrieNode();
            }
            cur = cur->children[i];
        }
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode *node = root;
        for (char c : word){
            int idx = c - 'a';
            if(node->children[idx]){
                node = node->children[idx];
            }
            else return false;
        }
        return node->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for (char c : prefix){
            int idx = c - 'a';
            if(node->children[idx]){
                node = node->children[idx];
            }
            else return false;
        }
        return true;
    }
};
