class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int maxlen = 0;
        int j = 0;
        for(int i=0 ; i<s.length() ; i++) {
            char ch = s[i];
            mp[ch]++;
            while(mp[ch] > 1) {
                mp[s[j]]--;
                j++;
            }

            maxlen = max(maxlen, i-j+1);
        }

        return maxlen;
    }
};
