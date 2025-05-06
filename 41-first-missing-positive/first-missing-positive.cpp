class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
            int n = nums.size();


    for (int i = 0; i < n; ++i) {
        if (nums[i] <= 0 || nums[i] > n)
            nums[i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        int val = nums[i] % (n + 1); 
        if (val >= 1 && val <= n) {
            nums[val - 1] += (n + 1);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (nums[i] <= n) {
            return i + 1;
        }
    }

    return n + 1;
    }
};