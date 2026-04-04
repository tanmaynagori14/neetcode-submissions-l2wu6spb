// class Solution {
// public:
//     int findLastValid(vector<vector<int>>& intervals, int q) {
//         int l = 0, r = intervals.size() - 1, ans = -1;
//         while (l <= r) {
//             int mid = l + (r - l) / 2;
//             if (intervals[mid][0] <= q) {
//                 ans = mid;
//                 l = mid + 1;
//             } else {
//                 r = mid - 1;
//             }
//         }
//         return ans;
//     }

//     vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
//         sort(intervals.begin(), intervals.end());

//         vector<int> res;

//         for (int q : queries) {
//             int idx = findLastValid(intervals, q);
//             int best = INT_MAX;

//             // scan all candidates with left <= q
//             for (int i = 0; i <= idx; i++) {
//                 if (intervals[i][1] >= q) {
//                     int len = intervals[i][1] - intervals[i][0] + 1;
//                     best = min(best, len);
//                     break;
//                 }
//             }

//             res.push_back(best == INT_MAX ? -1 : best);
//         }

//         return res;
//     }
// };


class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {

        sort(intervals.begin(), intervals.end());

        vector<pair<int,int>> qs;
        for (int i = 0; i < queries.size(); i++)
            qs.push_back({queries[i], i});

        sort(qs.begin(), qs.end());

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> ans(queries.size(), -1);
        int i = 0, n = intervals.size();

        for (auto &[q, idx] : qs) {

            // add intervals that start before or at q
            while (i < n && intervals[i][0] <= q) {
                int l = intervals[i][0];
                int r = intervals[i][1];
                pq.push({r - l + 1, r});
                i++;
            }

            // remove intervals that end before q
            while (!pq.empty() && pq.top().second < q) {
                pq.pop();
            }

            // answer for this query
            if (!pq.empty()) {
                ans[idx] = pq.top().first;
            }
        }

        return ans;
    }
};