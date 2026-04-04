// class Solution {
//     int n1, n2, n3;
//     vector<vector<vector<bool>>> dp;
//     bool fun(int i, int j, int k, string &s1, string &s2, string &s3) {
//         if (i == n1 && j == n2 && k == n3) {
//             return true;
//         }

//         if(i < n1 && j < n2) {
//             if(s1[i] != s3[k] && s2[j] != s3[k]) return false;
//         }

//         if(i < n1) {
//             if(s1[i] == s3[k]) {
//                 if(fun(i+1, j, k+1, s1, s2, s3)) return true;
//             }
//         }

//         if(j < n2) {
//             if(s2[j] == s3[k]) {
//                 if(fun(i, j+1, k+1, s1, s2, s3)) return true;
//             } 
//         }

//         return false;
//     }
// public:
//     bool isInterleave(string s1, string s2, string s3) {
//         n1 = s1.length(); n2 = s2.length() ; n3 = s3.length();
//         if(n1 + n2 != n3) return false;
//         dp.assign(vector<)
//         return fun(0, 0, 0, s1, s2, s3);
//     }
// };


class Solution {
    int n1, n2, n3;
    vector<vector<int>> dp;

    bool fun(int i, int j, string &s1, string &s2, string &s3) {

        if(i == n1 && j == n2)
            return true;

        if(dp[i][j] != -1)
            return dp[i][j];

        int k = i + j;

        bool ans = false;

        if(i < n1 && s1[i] == s3[k]) {
            ans = ans || fun(i+1, j, s1, s2, s3);
        }

        if(j < n2 && s2[j] == s3[k]) {
            ans = ans || fun(i, j+1, s1, s2, s3);
        }

        return dp[i][j] = ans;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        n1 = s1.length();
        n2 = s2.length();
        n3 = s3.length();

        if(n1 + n2 != n3) return false;

        dp.assign(n1+1, vector<int>(n2+1, -1));

        return fun(0,0,s1,s2,s3);
    }
};