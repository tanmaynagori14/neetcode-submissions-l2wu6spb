class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int indeg[numCourses] = {0};
        vector<int> adj[numCourses];
        for(auto it: prerequisites) {
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }

        vector<int> st;
        queue<int> q;
        for(int i=0 ; i<numCourses ; i++) {
            if(indeg[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int ele = q.front();
            st.push_back(ele);
            q.pop();
            for(auto it: adj[ele]) {
                indeg[it]--;
                if(indeg[it] == 0) {
                    q.push(it);
                }
            }
        }

        return st.size() == numCourses ? st : vector<int>{};
    }
};
