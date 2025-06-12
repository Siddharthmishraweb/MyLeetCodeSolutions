class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i = 0 ; i < nums.size() - 1; i++){
            maxi = max(abs(nums[i] - nums[i+1]), maxi);
        }
        maxi = max(maxi, abs(nums[nums.size() - 1] - nums[0]));
        return maxi;
    }
};