class Solution {
public:
    int findLastValid(vector<vector<int>>& intervals, int q) {
        int l = 0, r = intervals.size() - 1, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (intervals[mid][0] <= q) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }

    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());

        vector<int> res;

        for (int q : queries) {
            int idx = findLastValid(intervals, q);
            int best = INT_MAX;

            // scan all candidates with left <= q
            for (int i = 0; i <= idx; i++) {
                if (intervals[i][1] >= q) {
                    int len = intervals[i][1] - intervals[i][0] + 1;
                    best = min(best, len);
                }
            }

            res.push_back(best == INT_MAX ? -1 : best);
        }

        return res;
    }
};