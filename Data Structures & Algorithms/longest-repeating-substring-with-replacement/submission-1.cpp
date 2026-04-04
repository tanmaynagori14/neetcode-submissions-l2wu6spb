class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxfreq = 0, ans = 0;
        unordered_map<char, int> mp;
        int j = 0;
        for(int i=0 ; i<s.length() ; i++) {
            mp[s[i]]++;
            maxfreq = max(maxfreq, mp[s[i]]);
            int len = i - j + 1;
            if(len - maxfreq <= k) {
                ans = max(ans, len);
            } else {
                mp[s[j]]--;
                j++;
            }
        }

        return ans;
    }
};
