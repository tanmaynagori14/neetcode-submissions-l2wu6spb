// class Solution {
// public:
//     vector<int> partitionLabels(string s) {
//         vector<int> ans;
//         unordered_map<char,int> m;
//         for(int i=0 ; i<s.length() ; i++) {
//             m[s[i]] = i;
//         }

//         int l=0;
//         while(l < s.length()) {
//             char ch = s[l];
//             int rightIdxmax = m[ch];
//             int startIdx = l;
//             while(l <= rightIdxmax) {
//                 rightIdxmax = max(rightIdxmax, m[s[l]]);
//                 l++;
//             }
            
//             ans.push_back(rightIdxmax - startIdx + 1);
//             l = rightIdxmax+1;
//         }

//         return ans;
//     }
// };


class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;

        // last occurrence of each character
        vector<int> last(26, 0);
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, last[s[i] - 'a']);

            // when current index reaches partition end
            if (i == end) {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return ans;
    }
};