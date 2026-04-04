class Solution {
    vector<vector<string>> ans;
    int n;

    bool isPalindrome(int s, int e, string &str) {
        while(s<=e) {
            if(str[s] != str[e]) return false;
            s++; e--;
        }
        return true;
    }
    void fun(int idx, vector<string> &temp, string &s) {
        if(idx == n) {
            ans.push_back(temp);
            return;
        }

        for(int i=idx ; i<n ; i++) {
            if(isPalindrome(idx, i, s)) {
                temp.push_back(s.substr(idx, i-idx+1));
                fun(i+1, temp, s);
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        n = s.length();
        fun(0, temp, s);
        return ans;
    }
};
