class Solution {
public:
    void swap(int& a, int& b){
        int temp = b;
        b = a;
        a = temp;
    }
    void sortColors(vector<int>& nums) {
        if(nums.size() < 2) return ;
        // int frontPos = 0, endPos = nums.size() - 1;
        // int size = nums.size() <= 2 ? nums.size() :  (nums.size() / 2) + 1;
        // if(nums.size() == 2 && nums[0] == 2) size = nums.size()/2;
        // for(int i = 0 ; i < size ; i++){
        //     if(nums[i] == 2){
        //         swap(nums[i], nums[endPos]);
        //         endPos--;
        //     }
        //     if(nums[i] == 0){
        //         swap(nums[i], nums[frontPos]);
        //         frontPos++;
        //     }
        // }
        // int frontPos = 0, endPos = nums.size() - 1;
        // int size = nums.size() <= 2 ? nums.size() :  (nums.size() / 2) + 1;
        // if(nums.size() == 2 && nums[0] == 2) size = nums.size()/2;
        // for(int i = 0 ; i < size ; i++){
        //     if(nums[i] == 2){
        //         swap(nums[i], nums[endPos]);
        //         endPos--;
        //     }
        //     if(nums[i] == 0){
        //         swap(nums[i], nums[frontPos]);
        //         frontPos++;
        //     }
        // }
        // int i = 0, j = nums.size() - 1;
        // while(j >= i){
        //     if(nums[i] == 2){
        //         swap(nums[i], nums[j]);
        //         i++;
        //     }else if(nums[i] == 0){
        //         i++;
        //     }else if(nums[j] == 2){
        //         j--;
        //     }else{
        //         if(nums[j] == 0)
        //          swap(nums[i], nums[j]);
        //     }
        // }
        
        int i = 0, j = 0, k = nums.size() - 1;
        while(j <= k){
            if(nums[j] == 0){
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
            else if(nums[j] == 2){
                //cout<<"; => "<<nums[j]<<" , "<<nums[k]<<endl;
                swap(nums[j], nums[k]);
               // cout<<"2; => "<<nums[j]<<" , "<<nums[k]<<endl;

                //j++;
                k--;
            }else
            if(nums[j] == 1) j++;
        }
    }
};