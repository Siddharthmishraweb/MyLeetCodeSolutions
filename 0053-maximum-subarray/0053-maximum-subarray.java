class Solution {
    public int maxSubArray(int[] nums) {
        //kadane algo
        int max_sum_ending_here = 0;
        int max_sum = Integer.MIN_VALUE;
        for(int i =  0; i < nums.length; i++){
            max_sum_ending_here += nums[i];
            if(max_sum < max_sum_ending_here){
                max_sum = max_sum_ending_here;
            }
            if(max_sum_ending_here < 0)
                max_sum_ending_here = 0;
        }
        return max_sum;
    }
}