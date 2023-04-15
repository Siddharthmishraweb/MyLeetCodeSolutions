// class Solution {
// public:
//     // i => ith piles
//     int n = 0;
//     int K;
//     int dp[1001][1001];
//     int solve(vector<vector<int>> piles, int i, int k){
//         if(dp[i][k] > -1) return dp[i][k];
//         //base case 
//         if(i >= piles.size()) return 0;
//         if(k <= 0) return 0;
//         // not taken
//         int not_taken = solve(piles, i+1, k);
//         dp[i+1][k] = not_taken;
//         // taken
//         int sum = 0, maxR = 0;
//         //cout<<piles[i].size();
//         for(int j = 0 ; j < min(k,  (int)piles[i].size() ); j++){
//             // take from ith piles only
//             sum += piles[i][j];
//             // take from other piles as well
//             int money = 0;
//             if(k - (j + 1) >= 0){
//                 int asn = solve(piles, i+1, k - (j + 1));
//                 dp[i+1][k-(j+1)] = asn;
//                 money = sum + asn;
//             }
                
//             maxR = max(maxR, money);
//         }
//        // return max(maxR, not_taken);
//         dp[i][k] = max(maxR, not_taken);
//         return dp[i][k];
//     }
//     int maxValueOfCoins(vector<vector<int>>& piles, int k) {
//         memset(dp, -1, sizeof(dp));
//         n = piles.size();
//         int K = k;
//         return solve(piles, 0, k);
//     }
// };


class Solution {
    int helper(vector<vector<int>> &piles,int idx,int k,int n,vector<vector<int>> &dp){
        if(idx==n || k==0)return 0;//base case
        if(dp[idx][k]!=-1)return dp[idx][k];
        int notPick=helper(piles,idx+1,k,n,dp);
        int coins=k,sum=0,pick=0;
        for(int i=0;i<piles[idx].size() && coins>0;i++){
            sum+=piles[idx][i];
            coins--;
            int x=sum+helper(piles,idx+1,coins,n,dp);
            pick=max(pick,x);
        }
        return dp[idx][k]=max(pick,notPick);
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return helper(piles,0,k,n,dp);
    }
}; 
