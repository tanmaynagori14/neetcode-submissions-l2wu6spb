class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        vector<int> pse(n, 0), nse(n, 0);
        for(int i=0 ; i<n ; i++) { pse[i] = -1; nse[i] = n; }

        stack<int> st;
        for(int i=0 ; i<n ; i++) {
            if(st.empty()) {
                pse[i] = -1;
                st.push(i);
            } else {
                while(!st.empty() && h[st.top()] >= h[i]) st.pop();
                st.empty() ? pse[i] = -1 : pse[i] = st.top();
                st.push(i);
            }
        }

        while(!st.empty()) st.pop();

        for(int i=n-1 ; i>=0 ; i--) {
            if(st.empty()) {
                nse[i] = n;
                st.push(i);
            } else {
                while(!st.empty() && h[st.top()] >= h[i]) st.pop();
                st.empty() ? nse[i] = n : nse[i] = st.top();
                st.push(i);
            }
        }

        for(auto it: pse) cout << it << "  ";
        cout << endl;
        for(auto it: nse) cout << it << "  ";

        int maxarea = 0;
        for(int i=0 ; i<n ; i++) {
            maxarea = max(maxarea, h[i] * (nse[i] - pse[i] - 1));
        }

        return maxarea;
    }
};
