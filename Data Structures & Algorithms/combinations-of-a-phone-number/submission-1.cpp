// class Solution {
//     vector<string> ans;
//     map<int, vector<char>> m;

//     int n;

//     void fun(int idx, string& temp, string& d) {
//         if(idx == n) {
//             ans.push_back(temp);
//             return;
//         }

//         int currNum = d[idx] - '0';
//         for(auto it: m[currNum]) {
//             temp.push_back(it);
//             fun(idx+1, temp, d);
//             temp.pop_back();
//         }
//     }
// public:
//     vector<string> letterCombinations(string digits) {
//         n = digits.size();
//         string temp = "";
//         if(n==0) return ans;
//         m[2] = {'a', 'b', 'c'};
//         m[3] = {'d', 'e', 'f'};
//         m[4] = {'g', 'h', 'i'};
//         m[5] = {'j', 'k', 'l'};
//         m[6] = {'m', 'n', 'o'};
//         m[7] = {'p', 'q', 'r', 's'};
//         m[8] = {'t', 'u', 'v'};
//         m[9] = {'w', 'x', 'y', 'z'};
//         fun(0, temp, digits);
//         return ans;
//     }
// };


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mapping = {
            "",     "",     "abc", "def",
            "ghi",  "jkl",  "mno",
            "pqrs", "tuv",  "wxyz"
        };

        vector<string> result;
        string temp;

        backtrack(0, digits, mapping, temp, result);
        return result;
    }

private:
    void backtrack(int idx, string& digits, vector<string>& mapping,
                   string& temp, vector<string>& result) {
        
        if (idx == digits.size()) {
            result.push_back(temp);
            return;
        }

        string letters = mapping[digits[idx] - '0'];

        for (char c : letters) {
            temp.push_back(c);
            backtrack(idx + 1, digits, mapping, temp, result);
            temp.pop_back(); // backtrack
        }
    }
};
