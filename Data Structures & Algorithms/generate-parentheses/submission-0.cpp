class Solution {
    vector<string> ans;
    void fun(int o, int c, string &temp, int n) {
        if(o==n && c==n) {
            ans.push_back(temp);
            return;
        }

        if(o < n) {
            temp.push_back('(');
            fun(o+1, c, temp, n);
            temp.pop_back();
        }

        if(c<n && c < o) {
            temp.push_back(')');
            fun(o, c+1, temp, n);
            temp.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string temp;
        fun(0, 0, temp, n);
        return ans;
    }
};
