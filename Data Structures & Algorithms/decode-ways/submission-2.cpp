// class Solution {
//     int n;
//     vector<int> dp;
//     int fun(int idx, string &s) {
//         if(idx == s.length()) return 1;

//         if(dp[idx] != 0) return dp[idx];

//         int onedigit = 0, twodigit = 0;
//         if(s[idx] != '0') onedigit = fun(idx+1, s);
        
//         if(idx<n-1) {
//             char c1 = s[idx], c2 = s[idx+1];
//             int num = stoi(s.substr(idx, 2));
//             if(c1 != '0' && num >=1 && num<=26) {
//                 twodigit = fun(idx+2, s);
//             }
//         }

//         return dp[idx] = onedigit + twodigit;
//     }
// public:
//     int numDecodings(string s) {
//         n = s.length();
//         dp.assign(n+1, 0);
//         return fun(0, s);
//     }
// };



class Solution {
    int n;
    vector<int> dp;
    int fun(int idx, string &s) {
        if(idx == s.length()) return 1;

        if(dp[idx] != 0) return dp[idx];

        int onedigit = 0, twodigit = 0;
        if(s[idx] != '0') onedigit = fun(idx+1, s);
        
        if(idx<n-1) {
            char c1 = s[idx], c2 = s[idx+1];
            int num = stoi(s.substr(idx, 2));
            if(c1 != '0' && num >=1 && num<=26) {
                twodigit = fun(idx+2, s);
            }
        }

        return dp[idx] = onedigit + twodigit;
    }
public:
    int numDecodings(string s) {
        n = s.length();
        dp.assign(n+1, 0);
        dp[n] = 1;
        for(int i=n-1 ; i>=0 ; i--) {

            int onedigit = 0, twodigit = 0;
            if(s[i] != '0') onedigit = dp[i+1];
            
            if(i<n-1) {
                char c1 = s[i], c2 = s[i+1];
                int num = stoi(s.substr(i, 2));
                if(c1 != '0' && num >=1 && num<=26) {
                    twodigit = dp[i+2];
                }
            }

            dp[i] = onedigit + twodigit;
        }
        return dp[0];

    }
};
