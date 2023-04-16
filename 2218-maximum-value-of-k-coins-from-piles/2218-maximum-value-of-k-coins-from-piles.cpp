class Solution {
public:
    int n;
    int dp[1001][2001];
    int solve(vector<vector<int>>& piles, int i, int k){
        if(i >= n) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        int not_taken = solve(piles, i+1, k );
        int sum = 0, taken = 0;
        for(int j = 0 ; j < min((int)piles[i].size(), k); j++){
            sum += piles[i][j];
            taken = max(taken, sum + solve(piles, i+1, k - (j + 1)));
        }
        return dp[i][k] = max(taken, not_taken);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        if(k == 0) return 0;
        n = piles.size();
        memset(dp, -1, sizeof(dp));
        return solve(piles, 0, k);
    }
};