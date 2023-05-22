class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> freq;
        set<int> set;
        int n = nums.size();
        if(n == 1) return nums;
        for(auto i = 0 ; i < n ; i++) set.insert(nums[i]);
        for(int i = 0 ; i < n ; i++){
            freq[nums[i]]++;
        }
        
        int size = freq.size();
        vector<pair<int, int>> sol;
        for(auto x:set){
            sol.push_back({freq[x],x});
            cout<<x<<" , "<<freq[x]<<endl;
        }
        sort(sol.rbegin(), sol.rend());

        for(auto x:sol){
            cout<<x.first<<" , "<<x.second<<endl;
        }
        if(k == 1){
            ans.push_back(sol[0].second);
        }else{
            for(int i = 0 ; i < k  ; i++){
                ans.push_back(sol[i].second);
            }
        }
        
        //cout<<freq.size()<<endl;
        return ans;
    }
};