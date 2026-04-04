class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        vector<int> ans;
        int t=0, b=m.size()-1, l=0,r=m[0].size()-1;
        while(t<=b && l<=r) {
            for(int j=l ; j<=r ; j++) {
                ans.push_back(m[t][j]);
            }
            t++;
            if(t>b) break;
            for(int i=t ; i<=b ; i++) {
                ans.push_back(m[i][r]);
            }
            r--;
            if(l>r) break;
            for(int j=r ; j>=l ; j--) {
                ans.push_back(m[b][j]);
            }
            b--;
            if(t>b) break;
            for(int i=b ; i>=t ; i--) {
                ans.push_back(m[i][l]);
            }
            l++;
            if(l>r) break;
        }

        return ans;
    }
};
