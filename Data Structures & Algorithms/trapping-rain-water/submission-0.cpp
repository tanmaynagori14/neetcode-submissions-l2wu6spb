class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lmh(n, 0), rmh(n, 0);
        lmh[0] = height[0];
        rmh[n-1] = height[n-1];
        for(int i=1 ; i<n ; i++) {
            if(lmh[i-1] >= height[i]) lmh[i] = lmh[i-1];
            else lmh[i] = height[i];

            if(rmh[n-i] >= height[n-i-1]) rmh[n-i-1] = rmh[n-i];
            else rmh[n-i-1] = height[n-i-1]; 
        }

        int trappedwater = 0;
        for(int i=0 ; i<n ; i++) {
            trappedwater += min(lmh[i], rmh[i]) - height[i];
        }

        return trappedwater;
    }
};