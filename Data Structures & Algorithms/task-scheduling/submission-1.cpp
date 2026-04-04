// class Solution {
// public:
//     int leastInterval(vector<char>& tasks, int n) {
//         priority_queue<int> pq;
//         queue<pair<int, int>> q; // {freq, time it will be free}
//         unordered_map<int, int> frequencies;
//         for(auto it: tasks) frequencies[it]++;
//         for(auto &[key, freq]: frequencies) pq.push(freq);

//         int ans = 0;
//         while(!(pq.empty() && q.empty())) {
//             while(!q.empty()) {
//                 if(q.front().second <= ans) {
//                     pq.push(q.front().first);
//                     q.pop();
//                 } else break;
//             }

//             if(!pq.empty()) {
//                 int freq = pq.top();
//                 pq.pop();
//                 freq = freq-1;
//                 if(freq > 0) q.push({freq, ans + n+1});
//             }

//             ans++;
//         }

//         return ans;
//     }
// };


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> m(26, 0);
        for(auto it: tasks) m[it-'A']++;
        sort(m.begin(), m.end());
        int maxfreq = m[25];
        int gaddhe = maxfreq - 1;
        int idletime = gaddhe * n;

        for(int i=24 ; i>=0 ; i--) {
            idletime -= min(gaddhe, m[i]);
        }

        if(idletime > 0) {
            return tasks.size() + idletime;
        } 
        return tasks.size();
    }
};
