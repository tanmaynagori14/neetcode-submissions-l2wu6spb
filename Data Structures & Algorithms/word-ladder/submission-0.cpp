class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& wordList) {
        queue<string> q;
        q.push(bw);
        int steps = 0;
        unordered_set<string> wl;
        for(auto it: wordList) wl.insert(it);

        while(!q.empty()) {
            int sz = q.size();
            steps++;
            
            while(sz) {
                string word = q.front();
                if(word == ew) return steps;
                q.pop();
                
                if(wl.count(word) == 1) wl.erase(word);

                for(int i=0 ; i<word.length() ; i++) {
                    int currChar = word[i];
                    for(char ch = 'a' ; ch <= 'z' ; ch++) {
                        if(ch == currChar) continue;
                        word[i] = ch;
                        if(wl.count(word) == 1) q.push(word);
                    }
                    word[i] = currChar;
                }
                sz--;
            }

            
        }

        return 0;
    }
};
