class Solution {
public:
    int getSum(int a, int b) {
        // carry is obtaned by (a & b) << 1
        // number addition is done by a ^ b
        while(b != 0) {
            int temp = (a & b) << 1;
            a = a ^ b;
            b = temp;
        }

        return a;
    }
};
