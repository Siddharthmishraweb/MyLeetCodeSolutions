class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freq;
        for(auto a: s){
            freq[a]++;
        }
        int maxOdd = INT_MIN, minEven=INT_MAX;
        for(auto a: freq){
            if(a.second%2==0) minEven = min(minEven, a.second);
            else maxOdd = max(maxOdd, a.second);
        }
        return maxOdd - minEven;
    }
};