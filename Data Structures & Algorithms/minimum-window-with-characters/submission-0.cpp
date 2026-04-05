class Solution {
public:
    string minWindow(string s, string t) {
        int cnt = 0;
        int i=0, j=0;
        int ind = -1, minlen = INT_MAX;
        unordered_map<char, int> mp;
        for(auto ch: t) mp[ch]++;
        while(i<s.length()) {
            mp[s[i]]--;
            if(mp[s[i]] >= 0) cnt++;
            while(cnt == t.length()) {
                if(i - j + 1 < minlen) {
                    minlen = i - j + 1;
                    ind = j;
                }
                mp[s[j]]++;
                if(mp[s[j]] > 0) {
                    cnt--;
                }

                j++;
            }
            i++;
        }

        return ind == -1 ? "" : s.substr(ind, minlen);
    }
};
