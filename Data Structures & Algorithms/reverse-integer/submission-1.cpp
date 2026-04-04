class Solution {
public:
    int reverse(int x) {
        int ans = 0, n = x;
        
        while(n) {
            int lastdigit = n % 10;
            if(!(ans >= INT_MIN/10 && ans<= INT_MAX/10)) return 0;
            ans = ans*10 + lastdigit;
            n = n/10;
        }

        return ans;
    }
};
