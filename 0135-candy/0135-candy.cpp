class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans[ratings.size()];
        for(int i = 0 ; i < ratings.size(); i++) ans[i] = 1;
        // left to right
        for(int i = 1 ; i < ratings.size() ; i++){
            if(ratings[i] > ratings[i-1]){
                ans[i] = ans[i-1] + 1;
            }
        }
        // right
        for(int i = ratings.size() - 2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]){
                if(ans[i] <= ans[i+1]){
                    ans[i] = ans[i+1] + 1;
                }
            }
        }
        int sum = 0;
        for(auto x: ans) sum +=x;
        return sum;
    }
};