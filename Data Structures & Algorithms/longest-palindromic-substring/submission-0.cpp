class Solution {
public:
    string longestPalindrome(string str) {
        string res = "";
        for(int i=0 ; i<str.size() ; i++) {
            int s=i, e=i, len=0;
            while(s>=0 && e<=str.size()-1 && str[s] == str[e]) {
                len = e - s +1;
                if(len > res.length()) res = str.substr(s, len);
                s--; e++;
            }

            

            if(i!=0) {
                s=i-1; e=i;
                while(s>=0 && e<=str.size()-1 && str[s] == str[e]) {
                    len = e-s+1;
                    if(len > res.length()) res = str.substr(s, len);
                    s--; e++;
                }
            }
        }

        return res;
    }
};
