class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freq;
        for(auto a: s){
            freq[a]++;
        }
        int maxOdd = INT_MIN, minOdd=INT_MAX, minEven=INT_MAX, maxEven=INT_MIN;
        for(auto a: freq){
            cout<<"a.second:: "<<a.second<<endl;
            if(a.second%2==0){
                maxEven = max(maxEven, a.second);
                minEven = min(minEven, a.second);
            }else{
                maxOdd = max(maxOdd, a.second);
                minOdd = min(minOdd, a.second);
            }
        }

 

        return maxOdd - minEven;
    }
};