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
    static const bool comparator(Interval &a, Interval &b) {
        return a.start < b.start;
    }
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int maxRooms = 0;
        int currFilledRooms = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(intervals.begin(), intervals.end(), comparator);
        for(int i=0 ; i<intervals.size() ; i++) {
            int s = intervals[i].start, e = intervals[i].end;
            while(!pq.empty() && pq.top()<=s) {
                currFilledRooms--;
                pq.pop();
            }

            pq.push(e);

            if(currFilledRooms == maxRooms) {
                maxRooms++;
            }
            
            currFilledRooms++;
        }

        return maxRooms;
    }
};
