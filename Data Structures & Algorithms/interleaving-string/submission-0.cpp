class Solution {
    int n1, n2, n3;
    bool fun(int i, int j, int k, string &s1, string &s2, string &s3) {
        if (i == n1 && j == n2 && k == n3) {
            return true;
        }

        if(i < n1 && j < n2) {
            if(s1[i] != s3[k] && s2[j] != s3[k]) return false;
        }

        if(i < n1) {
            if(s1[i] == s3[k]) {
                if(fun(i+1, j, k+1, s1, s2, s3)) return true;
            }
        }

        if(j < n2) {
            if(s2[j] == s3[k]) {
                if(fun(i, j+1, k+1, s1, s2, s3)) return true;
            } 
        }

        return false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        n1 = s1.length(); n2 = s2.length() ; n3 = s3.length();
        if(n1 + n2 != n3) return false;
        return fun(0, 0, 0, s1, s2, s3);
    }
};
