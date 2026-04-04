class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i=0, n = intervals.size();
        while(i<n) {
            int s = intervals[i][0], e = intervals[i][1];
            if(newInterval[0] <= e) {
                // overlap break
                break;
            } else {
                ans.push_back(intervals[i]);
            }
            i++;
        }

        ans.push_back(newInterval);

        while(i<n) {
            int s = intervals[i][0], e = intervals[i][1];
            if(s <= ans.back()[1]) {
                ans.back()[0] = min(ans.back()[0], s);
                ans.back()[1] = max(ans.back()[1], e);
            } else {
                ans.push_back(intervals[i]);
            }
            i++;
        }

        return ans;

    }
};
