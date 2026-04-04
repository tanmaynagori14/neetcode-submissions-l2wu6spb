class Solution {
    string multiplySingle(string n1, int k) {
        int carry = 0;
        string ans = "";

        for (int i = n1.size() - 1; i >= 0; i--) {
            int num = (n1[i] - '0') * k + carry;
            ans.push_back(num % 10 + '0');
            carry = num / 10;
        }

        if (carry) ans.push_back(carry + '0');

        reverse(ans.begin(), ans.end());
        return ans;
    }

    string addStrings(string a, string b, int zeros) {
        if (a.empty()) {
            b.append(zeros, '0');
            return b;
        }

        b.append(zeros, '0');

        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        string res = "";

        while (i >= 0 || j >= 0 || carry) {
            int x = (i >= 0 ? a[i--] - '0' : 0);
            int y = (j >= 0 ? b[j--] - '0' : 0);
            int sum = x + y + carry;
            res.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        reverse(res.begin(), res.end());
        return res;
    }
public:
    string multiply(string n1, string n2) {
        if (n1 == "0" || n2 == "0") return "0";
        int m = n1.size();
        int n = n2.size();
        string ans = "";
        for(int i=n-1 ; i>=0 ; i--) {
            string mult = multiplySingle(n1, n2[i]-'0');
            ans = addStrings(ans, mult, n - 1 - i);
        }

        return ans;
    }
};


// class Solution {
//     string multiplySingle(string n1, int k) {
//         int carry = 0;
//         string ans = "";

//         for (int i = n1.size() - 1; i >= 0; i--) {
//             int num = (n1[i] - '0') * k + carry;
//             ans.push_back(num % 10 + '0');
//             carry = num / 10;
//         }

//         if (carry) ans.push_back(carry + '0');

//         reverse(ans.begin(), ans.end());
//         return ans;
//     }

//     string addStrings(string a, string b, int zeros) {
//         if (a.empty()) {
//             b.append(zeros, '0');
//             return b;
//         }

//         b.append(zeros, '0');

//         int i = a.size() - 1, j = b.size() - 1, carry = 0;
//         string res = "";

//         while (i >= 0 || j >= 0 || carry) {
//             int x = (i >= 0 ? a[i--] - '0' : 0);
//             int y = (j >= 0 ? b[j--] - '0' : 0);
//             int sum = x + y + carry;
//             res.push_back(sum % 10 + '0');
//             carry = sum / 10;
//         }

//         reverse(res.begin(), res.end());
//         return res;
//     }

// public:
//     string multiply(string n1, string n2) {
//         if (n1 == "0" || n2 == "0") return "0";

//         string ans = "";
//         int n = n2.size();

//         for (int i = n - 1; i >= 0; i--) {
//             string prod = multiplySingle(n1, n2[i] - '0');
//             ans = addStrings(ans, prod, n - 1 - i);
//         }

//         return ans;
//     }
// };