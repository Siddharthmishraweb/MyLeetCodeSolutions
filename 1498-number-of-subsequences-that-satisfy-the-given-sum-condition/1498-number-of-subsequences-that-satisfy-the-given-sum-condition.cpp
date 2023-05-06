class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        vector<int> exps(nums.size(), 1);
        const int MOD = 1e9+7;
        for(int i = 1;  i < nums.size() ; i++){
            exps[i] = ( 2 * (exps[i-1]) ) % MOD;
        }
        int cnt = 0;
        int left = 0, right = nums.size() - 1;
        sort(nums.begin(), nums.end());
        while(left <= right){
            if(nums[left] + nums[right] > target) right--;
            else{
                cnt = (cnt + exps[right - left]) % MOD;
                left++;
            }
        }
        return cnt;
    }
};