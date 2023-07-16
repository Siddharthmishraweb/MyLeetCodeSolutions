class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0 , j = 0, maxi = -9999;
        vector<int> ans;
        deque<int> q;
        while(j < nums.size()){
            while(!q.empty() && q.back() < nums[j]){
                q.pop_back();
            }
            q.push_back(nums[j]);
            int windowSize = j - i + 1;
            if(windowSize < k){
                j++;
            }
            if(windowSize == k){
                ans.push_back(q.front());
                if(q.front() == nums[i]){
                    q.pop_front();
                }
                i++;
                j++;
            }
            
        }
        return ans;
    }
};