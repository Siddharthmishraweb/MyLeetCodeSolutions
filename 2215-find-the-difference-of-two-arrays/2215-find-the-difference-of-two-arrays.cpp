class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans1,ans2;
        set<int> set1, set2;
        unordered_map<int, int> freq1;
        unordered_map<int,int> freq2;
        
        for(int i = 0 ; i < nums1.size() ; i++){
            freq1[nums1[i]]++;
        }
        for(int j = 0 ; j < nums2.size() ; j++){
                freq2[nums2[j]]++;
        }
        for(int i = 0 ; i< nums2.size(); i++){
            if(freq1.find(nums2[i]) == freq1.end()){
                set2.insert(nums2[i]);
                //ans2.push_back(nums2[i]);
            }
        }
        for(int i = 0 ; i< nums1.size(); i++){
            if(freq2.find(nums1[i]) == freq2.end()){
                set1.insert(nums1[i]);
                //ans1.push_back(nums1[i]);
            }
        }
        for(auto x: set1) ans1.push_back(x);
        for(auto x: set2) ans2.push_back(x);
        vector<vector<int>> ans;
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};