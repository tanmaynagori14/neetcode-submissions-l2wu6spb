class Trie {
public:
    unordered_map<char, Trie*> children;
    bool iwe = false;
};

class PrefixTree {
    Trie *root;
public:
    PrefixTree() {
        root = new Trie();
    }
    
    void insert(string word) {
        Trie *node = root;
        for(char ch: word) {
            if(!node->children.count(ch)) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }

        node->iwe = true;
    }
    
    bool search(string word) {
        Trie *node = root;
        for(char ch: word) {
            if(!node->children.count(ch)) {
                return false;
            }
            node = node->children[ch];
        }

        return node->iwe;
    }
    
    bool startsWith(string prefix) {
        Trie *node = root;
        for(char ch: prefix) {
            if(!node->children.count(ch)) {
                return false;
            }
            node = node->children[ch];
        }

        return true;
    }
};
