class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        int _n = abs(n);
        while(_n) {
            if(_n%2 == 1) {
                ans = ans * x;
                _n = _n-1;
            } else {
                x = x * x;
                _n = _n/2;
            }
        }

        if(n < 0) ans = 1.0 / ans;
        return ans;
    }
};
