class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        queue<pair<int, int>> q; // {freq, time it will be free}
        unordered_map<int, int> frequencies;
        for(auto it: tasks) frequencies[it]++;
        for(auto &[key, freq]: frequencies) pq.push(freq);

        int ans = 0;
        while(!(pq.empty() && q.empty())) {
            while(!q.empty()) {
                if(q.front().second <= ans) {
                    pq.push(q.front().first);
                    q.pop();
                } else break;
            }

            if(!pq.empty()) {
                int freq = pq.top();
                pq.pop();
                freq = freq-1;
                if(freq > 0) q.push({freq, ans + n+1});
            }

            ans++;
        }

        return ans;
    }
};
