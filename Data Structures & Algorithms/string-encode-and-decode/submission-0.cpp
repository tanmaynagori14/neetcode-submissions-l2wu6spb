class Solution {
public:

    // Encode
    string encode(vector<string>& strs) {
        string ans = "";
        
        for(string &s : strs) {
            ans += to_string(s.size()) + '#' + s;
        }
        
        return ans;
    }

    // Decode
    vector<string> decode(string s) {
        vector<string> ans;
        
        int i = 0;
        while(i < s.size()) {
            
            // Step 1: extract length
            int j = i;
            while(s[j] != '#') j++;
            
            int len = stoi(s.substr(i, j - i));
            
            // Step 2: extract string
            string word = s.substr(j + 1, len);
            ans.push_back(word);
            
            // Step 3: move pointer
            i = j + 1 + len;
        }
        
        return ans;
    }
};