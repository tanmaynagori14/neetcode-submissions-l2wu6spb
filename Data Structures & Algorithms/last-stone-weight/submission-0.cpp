class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while(!pq.empty() && pq.size()>1) {
            int s1 = pq.top(); pq.pop();
            int s2 = pq.top(); pq.pop();

            if(s1 == s2) continue;
            else pq.push(s1-s2);
        }

        return pq.empty() ? 0 : pq.top();
    }
};
