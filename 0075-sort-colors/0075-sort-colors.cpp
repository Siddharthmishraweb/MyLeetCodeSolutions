class Solution {
public:
    void swap(int& a, int& b){
        int temp = b;
        b = a;
        a = temp;
    }
    void sortColors(vector<int>& nums) {
        if(nums.size() < 2) return ;
        
        int i = 0, j = 0, k = nums.size() - 1;
        while(j <= k){
            if(nums[j] == 0){
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
            else if(nums[j] == 2){
                swap(nums[j], nums[k]);
                k--;
            }else j++;
        }
    }
};