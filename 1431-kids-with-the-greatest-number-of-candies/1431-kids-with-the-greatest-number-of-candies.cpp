class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
       vector<int> candieswith(candies);
       vector<int> ex(candies); 
       vector<bool> ans;
       int n = candies.size();
       for(int i = 0 ; i < n; i++){
           candieswith[i] += extraCandies;
           sort(candies.begin(), candies.end());
           cout<<candieswith[n-1]<<" "<<candies[n-1]<<endl;
           if(candies[n-1] <= candieswith[i])
               ans.push_back(true);
           else ans.push_back(false);
           candies= ex;
           candieswith = candies;
       }
       return ans;
    }
};