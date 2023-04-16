class Solution {
public:
    // i => ith piles
    int n = 0;
    //int dp[1001][1001];
    int solve(vector<vector<int>>& piles, int i, int k, vector<vector<int>>& dp){
        if(dp[i][k] != -1) return dp[i][k];
        //base case 
        if(i >= piles.size()) return 0;
        if(k <= 0) return 0;
        // not taken
        int not_taken = solve(piles, i+1, k , dp);
        
        // taken
        int sum = 0, maxR = 0;
        //cout<<piles[i].size();
        for(int j = 0 ; j < min(k,  (int)piles[i].size() ); j++){
            // take from ith piles only
            sum += piles[i][j];
            // take from other piles as well
            int money = 0;
            if(k - (j + 1) >= 0){
                money = sum + solve(piles, i+1, k - (j + 1), dp);
            }
                
            maxR = max(maxR, money);
        }
       // return max(maxR, not_taken);
        
        return dp[i][k] = max(maxR, not_taken);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        //memset(dp, -1, sizeof(dp));
        n = piles.size();
       vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        n = piles.size();
        return solve(piles, 0, k, dp);
    }
};