class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        unordered_map<char,int> m;
        for(int i=0 ; i<s.length() ; i++) {
            m[s[i]] = i;
        }

        int l=0;
        while(l < s.length()) {
            char ch = s[l];
            int rightIdxmax = m[ch];
            int startIdx = l;
            while(l <= rightIdxmax) {
                rightIdxmax = max(rightIdxmax, m[s[l]]);
                l++;
            }
            
            ans.push_back(rightIdxmax - startIdx + 1);
            l = rightIdxmax+1;
        }

        return ans;
    }
};
