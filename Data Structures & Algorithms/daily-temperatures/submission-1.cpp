class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& ts) {
        int n = ts.size();
        stack<pair<int, int>> st;
        vector<int> resp(n, 0);
        for(int i=n-1 ; i>=0 ; i--) {
            if(!st.empty()) {
                while(!st.empty() && st.top().first <= ts[i]) {
                    st.pop();
                }

                if(!st.empty()) {
                    resp[i] = st.top().second - i;
                }
            }

            st.push({ts[i], i}); // {temp, idx}
        }

        return resp;
    }
};
