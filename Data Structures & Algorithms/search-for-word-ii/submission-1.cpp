class Trie {
public:
    unordered_map<char, Trie*> children;
    bool isWordEnd = false;
};

class Solution {
private:
    int m, n;
    vector<vector<int>> vis;
    vector<string> ans;
    int delr[4] = {-1, 0, 1, 0};
    int delc[4] = {0, -1, 0, 1};

public:
    void insert(string word, Trie* root) {
        Trie *node = root;
        for(char ch: word) {
            if (node->children.count(ch) != 1) {
                node->children[ch] = new Trie();
            }
            
            node = node->children[ch];
        }

        node->isWordEnd = true;
    }

    void dfs(int r, int c, string currWord, vector<vector<char>>& b, Trie *node) {
        char ch = b[r][c];

        // 1. Check if current char exists
        if (node->children.count(ch) == 0) return;

        vis[r][c] = 1;

        // 2. Move to child
        node = node->children[ch];
        currWord.push_back(ch);

        // 3. Check word end AFTER consuming character
        if (node->isWordEnd) {
            ans.push_back(currWord);
            node->isWordEnd = false; // avoid duplicates
        }


        for(int i=0 ; i<4 ; i++) {
            int nr = r + delr[i];
            int nc = c + delc[i];
            if(nr>=0 && nc>=0 && nr<m && nc<n && !vis[nr][nc]) {
                dfs(nr, nc, currWord, b, node);
            }
        }

        currWord.pop_back();
        vis[r][c] = 0;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *root = new Trie();

        for(string str: words) {
            insert(str, root);
        }

        m = board.size(); n = board[0].size();
        vis.assign(m, vector<int>(n, 0));

        for(int i=0 ; i<m ; i++) {
            for(int j=0 ; j<n ; j++) {
                dfs(i, j, "", board, root);
            }
        }

        return ans;
    }
};
