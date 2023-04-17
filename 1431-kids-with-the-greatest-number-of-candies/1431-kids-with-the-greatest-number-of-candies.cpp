class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
       vector<bool> ans;
       int maximum = INT_MIN;
       int n = candies.size();
       for(int i = 0 ; i < n ; i++){
           maximum = max(maximum, candies[i]);
       }
       for(int i = 0 ; i < n; i++){
           int candwithExtra = candies[i]+extraCandies;
           if(maximum <= candwithExtra)
               ans.push_back(true);
           else ans.push_back(false);
       }
       return ans;
    }
};