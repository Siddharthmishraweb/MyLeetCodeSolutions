

#define ll long long 
class Solution {
public:
    int arraySign(vector<int>& nums) {
        ll pro = 1;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] > 0) nums[i] = 1;
            if(nums[i] < 0) nums[i] = -1;
            if(nums[i] == 0) nums[i] = 0;
        }
        for(auto x: nums) pro = pro * x;
        //cout<<pro<<endl;
        if(pro > 0) return 1;
        else if(pro < 0) return -1;
        return 0;
    }
};