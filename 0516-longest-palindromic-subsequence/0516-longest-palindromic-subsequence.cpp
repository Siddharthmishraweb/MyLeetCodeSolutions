class Solution {
public:
    // //recursive solution
    // int lcs(string s1,string s2, int m, int n){
    //     // base condition
    //     if(m == 0 || n == 0) return 0;
    //     if(s1[m-1] == s2[n-1]) return 1 + lcs(s1,s2,m-1,n-1);
    //     else{
    //         return max(lcs(s1,s2,m-1,n), lcs(s1,s2,m,n-1));
    //     }
    //     return 0;
    // }
    // int longestPalindromeSubseq(string s) {
    //     string s2 = s;
    //     reverse(s2.begin(), s2.end());
    //     return lcs(s,s2 ,s.size(),s.size());
    // }

    
    
    //memoization solution
//     int dp[1000][1000];
//     int lcs(string s1,string s2, int m, int n){

//         // base condition
//         if(m == 0 || n == 0) return 0;
        
//         if(dp[m][n] != -1) return dp[m][n];
        
//         if(s1[m-1] == s2[n-1]){
//             dp[m][n] = 1 + lcs(s1,s2,m-1,n-1);
//         }
//         else{
//             dp[m][n] =  max(lcs(s1,s2,m-1,n), lcs(s1,s2,m,n-1));
//         }

//         // return dp[m][n] = s1[m-1] == s2[n-1] ? 1 + lcs(s1,s2,m-1,n-1) : max(lcs(s1,s2,m-1,n), lcs(s1,s2,m,n-1));
        
//     }


    //Top down approch DP solution
    int lcs(string s1,string s2, int m, int n){
        int dp[m+1][n+1];
        for(int i = 0 ; i < m+1 ; i++){
            dp[i][0] = 0;
            dp[0][i] = 0;
        }
        for(int i = 1 ; i < m+ 1; i++){
            for(int j = 1 ;j < n + 1 ; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }

    int longestPalindromeSubseq(string s) {
        string s2 = s;
        // int dp[s.size()+1][s.size()+1];
        //memset(dp, -1,sizeof(dp));
        reverse(s2.begin(), s2.end());
        return lcs(s,s2 ,s.size(),s.size());
    }    
    
    
    
};