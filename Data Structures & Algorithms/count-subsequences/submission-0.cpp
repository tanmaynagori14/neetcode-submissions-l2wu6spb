class Solution {
    int fun(int i, int j, string &s, string &t) {
        if(i == s.size() || j == t.size()) {
            if(j == t.size()) return 1;
            return 0;
        }

        int nottake = fun(i+1, j, s, t);
        int take = 0;
        if(s[i] == t[j]) {
            take = fun(i+1, j+1, s, t);
        }

        return take + nottake;
    }
public:
    int numDistinct(string s, string t) {
        return fun(0, 0, s, t);
    }
};
