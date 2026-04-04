/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty()) return true;

        // Sort by start time
        sort(intervals.begin(), intervals.end(),
             [](const Interval &a, const Interval &b) {
                 return a.start < b.start;
             });

        int lastEnd = intervals[0].end;

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start < lastEnd) {
                return false;  // overlap
            }
            lastEnd = intervals[i].end;
        }

        return true;
    }
};