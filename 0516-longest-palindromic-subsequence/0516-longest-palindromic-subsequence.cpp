class Solution {
public:
    int lcs(string a, string b, int m, int n){
        int dp[m+1][n+1];
        for(int i = 0 ; i < m ; i++){
            dp[i][0] = 0;
            dp[0][i] = 0;
        }
        for(int i = 1; i < m + 1; i++){
            for(int j = 1; j < n + 1; j++){
                if(a[i-1] == b[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s.begin(), s.end());
        return lcs(s2,s,s.size(), s.size());
    }
};