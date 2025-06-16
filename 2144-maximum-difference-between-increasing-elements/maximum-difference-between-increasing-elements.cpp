class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minSofar = nums[0];
        int maxDiff = -1;
        for(int i = 1 ; i < nums.size(); i++){
            minSofar = min(minSofar, nums[i]);
            if(nums[i] > minSofar) maxDiff = max(maxDiff, nums[i] - minSofar);
        }
        return maxDiff;
    }
};