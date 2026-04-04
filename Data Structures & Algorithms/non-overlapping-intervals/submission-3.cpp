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


// When intervals overlap, always keep the one that ends earlier — it blocks the least future space.

// We sort intervals by their end time (not start time) because of the greedy strategy:
// when two intervals overlap, it is always optimal to keep the one that ends earlier.
// 
// Example:
// intervals = [[1,100], [2,3], [3,4], [4,5]]
//
// If we sort by start time and keep [1,100], it overlaps with all others,
// leading to 3 removals. However, this is suboptimal.
//
// By sorting by end time, we encounter [2,3], [3,4], [4,5] first and keep them,
// removing only [1,100]. This minimizes removals.
//
// Intuition:
// Keeping the interval that finishes earliest leaves maximum room
// for future intervals, which guarantees the minimum number of removals.

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
