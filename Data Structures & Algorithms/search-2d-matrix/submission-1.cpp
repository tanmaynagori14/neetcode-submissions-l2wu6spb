class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int t) {
        int m = arr.size(), n = arr[0].size();
        int i=0, j=m*n-1;

        while(i<=j) {
            int mid = (i+j)/2;
            int p = mid/n, q = mid%n;
            if(t == arr[p][q]) return true;
            else if(t > arr[p][q]) i = mid+1;
            else j = mid-1;
        }

        return false;
    }
};
