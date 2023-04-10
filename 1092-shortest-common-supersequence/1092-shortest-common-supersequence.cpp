class Solution {
public:
    string s = "";
    int lcs(string s1, string s2, int m, int n){
        int dp[m+1][n+1];
        for(int i = 0 ; i <= m ; i++){
            dp[i][0] = 0;
        }
        for(int i = 0 ; i <= n ; i++){
            dp[0][i] = 0;
        }
        for(int i = 0 ; i <= m ; i++){
             for(int j = 0 ; j <= n; j++){
                 dp[i][j]=0;
             }
        }
        for(int i = 1 ; i < m + 1 ; i++){
            for(int j = 1 ; j < n + 1; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int i = m, j = n;
        while(i > 0 && j > 0){
            if(s1[i-1] == s2[j-1]){
                s.push_back(s1[i-1]);
                i--;
                j--;
            }else{
                if(dp[i-1][j] > dp[i][j-1]){
                    s.push_back(s1[i-1]);
                    i--;
                }else{
                    s.push_back(s2[j-1]);
                    j--;
                }
            }
        }
        while(i > 0){
            s.push_back(s1[i-1]);
            i--;
        }
        while(j > 0){
            s.push_back(s2[j-1]);
            j--;
        }
        return dp[m][n];
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        lcs(str1, str2, m , n);
        reverse(s.begin(),s.end());
        return s;
    }
};