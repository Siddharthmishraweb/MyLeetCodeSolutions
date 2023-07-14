class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int minOne = INT_MAX;
        int minTwo = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < minOne){
                minOne = nums[i];
            }
             if(minOne < nums[i]){
                minTwo = min(minTwo,nums[i]);
            }
             if(minTwo < nums[i]){
                return true;
            }
        }
        return false;
    }
};