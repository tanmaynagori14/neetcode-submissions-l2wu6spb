class Solution {
public:
    int expand(string &s, int l, int r) {
        int count = 0;
        
        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            count++;
            l--;
            r++;
        }
        
        return count;
    }

    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            ans += expand(s, i, i);     // odd length
            ans += expand(s, i, i + 1); // even length
        }

        return ans;
    }
};