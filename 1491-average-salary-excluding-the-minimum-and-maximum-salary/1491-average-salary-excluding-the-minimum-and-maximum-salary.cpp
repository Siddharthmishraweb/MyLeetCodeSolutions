class Solution {
public:
    double average(vector<int>& salary) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i = 0 ; i < salary.size() ; i++){
            mini = min(salary[i], mini);
            maxi = max(maxi, salary[i]);
        }
        int ans = 0;
        for(int i = 0 ; i < salary.size() ; i++){
            if(salary[i] != maxi && salary[i] != mini){
                ans += salary[i];
            }
        }
        cout<<ans;
        return (1.0) * ans / ((1.0* (salary.size() - 2)));
    }
};