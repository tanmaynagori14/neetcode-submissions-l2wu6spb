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
    public int longestCommonSubsequence(String s1, String s2) {
        int l1 = s1.length();
        int l2 = s2.length();

        int[][] dp = new int[l1+1][l2+1];

        for(int i=0 ; i<l1 ; i++) {
            for(int j=0 ; j<l2 ; j++) {
                dp[i][j] = (int)(-1e9);
            }
        }
        dp[l1][l2] = 0;

        int[] next = new int[l2+1];
        // int[] curr = new int[l2+1];

        // for(int i=0 ; i<=l2 ; i++) {
        //     next[i] = (int)(-1e9);
        //     // curr[i] = (int)(-1e9);
        // }

        // next[l2] = 0;

        for(int i=l1-1 ; i>=0 ; i--) {
            int[] curr = new int[l2 + 1]; 
            for(int j=l2-1 ; j>=0 ; j--) {
                if(s1.charAt(i) == s2.charAt(j)) curr[j] = 1 + next[j+1];
                else curr[j] = Math.max(next[j], curr[j+1]);
            }

            next = curr;
        }

        return Math.max(0, next[0]);
    }
}
