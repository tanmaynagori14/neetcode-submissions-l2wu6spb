// class Solution {
//     int n, m;

//     bool fun(int i, int j, string &s, string &p) {
//         // correct base case
//         if (j == n) return i == m;

//         // handle when string is finished
//         if (i == m) {
//             if (j + 1 < n && p[j + 1] == '*')
//                 return fun(i, j + 2, s, p);
//             return false;
//         }

//         // normal match or '.'
//         if (s[i] == p[j] || p[j] == '.') {
//             // check if next is '*'
//             if (j + 1 < n && p[j + 1] == '*') {
//                 return fun(i + 1, j, s, p) || fun(i, j + 2, s, p);
//             } else {
//                 return fun(i + 1, j + 1, s, p);
//             }
//         }

//         // if next is '*' → skip pattern
//         if (j + 1 < n && p[j + 1] == '*') {
//             return fun(i, j + 2, s, p);
//         }

//         return false;
//     }

// public:
//     bool isMatch(string s, string p) {
//         m = s.length();
//         n = p.length();
//         return fun(0, 0, s, p);
//     }
// };



class Solution {
    int n, m;
    vector<vector<int>> dp;

    bool fun(int i, int j, string &s, string &p) {
        // check memo
        if (dp[i][j] != -1) return dp[i][j];

        // base case
        if (j == n) return dp[i][j] = (i == m);

        // handle when string is finished
        if (i == m) {
            if (j + 1 < n && p[j + 1] == '*')
                return dp[i][j] = fun(i, j + 2, s, p);
            return dp[i][j] = false;
        }

        // match condition
        if (s[i] == p[j] || p[j] == '.') {
            if (j + 1 < n && p[j + 1] == '*') {
                return dp[i][j] = (fun(i + 1, j, s, p) || fun(i, j + 2, s, p));
            } else {
                return dp[i][j] = fun(i + 1, j + 1, s, p);
            }
        }

        // skip pattern if '*'
        if (j + 1 < n && p[j + 1] == '*') {
            return dp[i][j] = fun(i, j + 2, s, p);
        }

        return dp[i][j] = false;
    }

public:
    bool isMatch(string s, string p) {
        m = s.length();
        n = p.length();

        dp.assign(m + 1, vector<int>(n + 1, -1));

        return fun(0, 0, s, p);
    }
};