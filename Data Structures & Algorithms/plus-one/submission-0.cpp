class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>out;
        int n = digits.size();
        int carry = 1;
        for(int i=n-1 ; i>=0 ; i--){
            int sum = digits[i] + carry;
            carry = sum / 10;
            int resp = sum % 10;
            out.push_back(resp);
        }

        while (carry) {
            out.push_back(carry);
            carry = carry/10;
        }

        reverse(out.begin(),out.end());

        return out;
    }
};
