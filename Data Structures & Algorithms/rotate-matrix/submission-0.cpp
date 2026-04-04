class Solution {
public:
    void rotate(vector<vector<int>>& arr) {

        int n = arr.size();

        // Step 1: Transpose
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                arr[i][j] = arr[i][j] + arr[j][i];
                arr[j][i] = arr[i][j] - arr[j][i];
                arr[i][j] = arr[i][j] - arr[j][i];
            }
        }

        // Step 2: Reverse each row
        for(int i = 0; i < n; i++) {

            int left = 0, right = n-1;

            while(left < right) {

                arr[i][left] = arr[i][left] + arr[i][right];
                arr[i][right] = arr[i][left] - arr[i][right];
                arr[i][left] = arr[i][left] - arr[i][right];

                left++;
                right--;
            }
        }
    }
};