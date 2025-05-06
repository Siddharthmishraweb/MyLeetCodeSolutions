class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        for(int i = 0 ; i < n ; i++){
          int x = nums[i];
          int y = nums[i + n];
          nums[i] = x + 10000 * (y % 10000);
        }
        for(int i = n - 1 ; i >= 0 ; i--){
          int x = nums[i] % 10000;
          int y = floor(nums[i] / 10000);
          cout<<"x: "<< x<<" y: "<<y <<endl;
          nums[2 * i] = x;
          nums [2*i + 1] = y;
        }
        return nums;
    }
};