// class Solution {
//     int l1, l2;
//     int fun(int i, int j, String s1, String s2) {
//         if(i == l1 && j == l2) return 0;
//         if(i >= l1 || j >= l2) return Integer.MIN_VALUE;
        
//         if(s1.charAt(i) == s2.charAt(j)) return 1 + fun(i+1, j+1, s1, s2);
//         else return Math.max(fun(i+1, j, s1, s2), fun(i, j+1, s1, s2));
//     }

//     public int longestCommonSubsequence(String text1, String text2) {
//         l1 = text1.length();
//         l2 = text2.length();

//         return Math.max(0, fun(0, 0, text1, text2));
//     }
// }


class Solution {
    int l1, l2;
    int fun(int i, int j, String s1, String s2) {
        if(i == l1 && j == l2) return 0;
        if(i >= l1 || j >= l2) return Integer.MIN_VALUE;
        
        if(s1.charAt(i) == s2.charAt(j)) return 1 + fun(i+1, j+1, s1, s2);
        else return Math.max(fun(i+1, j, s1, s2), fun(i, j+1, s1, s2));
    }

    public int longestCommonSubsequence(String s1, String s2) {
        l1 = s1.length();
        l2 = s2.length();

        int[][] dp = new int[l1+1][l2+1];

        for(int i=0 ; i<l1 ; i++) {
            for(int j=0 ; j<l2 ; j++) {
                dp[i][j] = (int)(-1e9);
            }
        }
        dp[l1][l2] = 0;

        for(int i=l1-1 ; i>=0 ; i--) {
            for(int j=l2-1 ; j>=0 ; j--) {
                if(s1.charAt(i) == s2.charAt(j)) dp[i][j] = 1 + dp[i+1][j+1];
                else dp[i][j] = Math.max(dp[i+1][j], dp[i][j+1]);
            }
        }

        return Math.max(0, dp[0][0]);
    }
}
