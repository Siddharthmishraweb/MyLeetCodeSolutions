class Solution {
public:
    int dp[3001][31];
    int helper(vector<int>& nums, int sum1, int totalSum, int index) {
        if (index == nums.size()) {
            int sum2 = totalSum - sum1;
            return abs(sum1 - sum2);
        }
        if(dp[sum1][index] != -1) return dp[sum1][index];
        
        int ans1 = helper(nums, sum1 + nums[index], totalSum, index + 1);
        int ans2 = helper(nums, sum1, totalSum, index + 1);
        dp[sum1][index] = min(ans1, ans2);
        return dp[sum1][index];
    }
    int lastStoneWeightII(vector<int>& stones) {
        memset(dp, -1, sizeof(dp));
        int sum = 0;
        for(auto a: stones) sum += a;
        return helper(stones, 0, sum, 0);
    }
};