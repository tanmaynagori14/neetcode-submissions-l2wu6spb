// class Solution {
//     unordered_set<string> st;
//     int n;
//     bool fun(int idx, string &s) {

//         if(idx == n) return true;

//         for(int i=idx ; i<n ; i++) {
//             if(st.count(s.substr(idx, i-idx+1))) {
//                 if(fun(i+1, s)) return true;
//             }
//         }

//         return false;
//     }
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         for(auto it: wordDict) st.insert(it);
//         n = s.length();
//         return fun(0, s);
//     }
// };


class Solution {
    unordered_set<string> st;
    vector<int> dp;
    int n;

    bool fun(int idx, string &s) {
        if(idx == n) return true;
        if(dp[idx] != -1) return dp[idx];

        for(int i = idx; i < n; i++) {
            if(st.count(s.substr(idx, i-idx+1))) {
                if(fun(i+1, s))
                    return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {

        for(auto &it : wordDict)
            st.insert(it);

        n = s.length();
        dp.assign(n, -1);
        return fun(0, s);
    }
};