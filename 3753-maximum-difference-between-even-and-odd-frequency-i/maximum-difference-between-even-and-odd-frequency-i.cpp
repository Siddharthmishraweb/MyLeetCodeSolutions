class Solution {
public:
    int maxDifference(string s) {
        int charArray[26];
        int maxOdd = INT_MIN;
        int minEven = INT_MAX;
        for(auto a: s){
            charArray[a - 'a']++;
        }

        for(auto a: charArray){
            if(a == 0) continue;
            if(a % 2 == 0){
                cout << a<<endl;
                minEven = min(minEven, a);
            }else{
                maxOdd = max(maxOdd, a);
            }
        }
        return maxOdd - minEven;
    }
};