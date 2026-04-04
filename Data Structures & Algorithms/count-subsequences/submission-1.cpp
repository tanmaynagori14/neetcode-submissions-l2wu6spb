class Solution {
    int m, n;
    int fun(int i, int j, string &s, string &t) {
        if(i == m || j == n) {
            if(j == n) return 1;
            return 0;
        }

        int nottake = 0;
        if(m-i-1 >= n-j) nottake = fun(i+1, j, s, t);
        int take = 0;
        if(s[i] == t[j]) {
            take = fun(i+1, j+1, s, t);
        }

        return take + nottake;
    }
public:
    int numDistinct(string s, string t) {
        m = s.length(); n = t.length();
        return fun(0, 0, s, t);
    }
};
