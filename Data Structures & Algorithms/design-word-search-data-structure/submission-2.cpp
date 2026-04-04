class Trie {
public:
    unordered_map<char, Trie*> children;
    bool isWordEnd = false;
};

class WordDictionary {
    Trie *root;

public:
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie *node = root;
        for(char ch: word) {
            if(!node->children.count(ch)) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isWordEnd = true;
    }
    
    bool dfs(int i, string &word, Trie *node) {
        if (i == word.length())
            return node->isWordEnd;

        char ch = word[i];

        if (ch != '.') {
            if (!node->children.count(ch)) return false;
            return dfs(i + 1, word, node->children[ch]);
        } else {
            for (auto &p : node->children) {
                if (dfs(i + 1, word, p.second))
                    return true;
            }
            return false;
        }
    }

    bool search(string word) {
        return dfs(0, word, root);
    }
};
