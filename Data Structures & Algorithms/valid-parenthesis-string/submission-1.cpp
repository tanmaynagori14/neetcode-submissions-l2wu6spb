class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0, maxOpen = 0;

        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } else if (c == ')') {
                minOpen--;
                maxOpen--;
            } else { // '*'
                minOpen--;     // treat '*' as ')'
                maxOpen++;     // treat '*' as '('
            }

            if (maxOpen < 0) return false;
            minOpen = max(0, minOpen);  // 🔑 critical fix
        }

        return minOpen == 0;
    }
};