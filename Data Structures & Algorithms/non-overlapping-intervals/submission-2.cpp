// class Solution {
// public:
//     int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//         sort(intervals.begin(), intervals.end());
//         int ans = 0;
//         vector<int> lastinterval;
//         for(auto it: intervals) {
//             if(lastinterval.empty()) {
//                 lastinterval = {it[0], it[1]};
//             } else {
//                 if(it[0] < lastinterval[1]) {
//                     // overlap
//                     ans++;
//                 } else {
//                     lastinterval = {it[0], it[1]};
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution {
    static const bool comparator(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comparator);
        int ans = 0;
        vector<int> lastinterval;
        for(auto it: intervals) {
            if(lastinterval.empty()) {
                lastinterval = {it[0], it[1]};
            } else {
                if(it[0] < lastinterval[1]) {
                    // overlap
                    ans++;
                } else {
                    lastinterval = {it[0], it[1]};
                }
            }
        }

        return ans;
    }
};
