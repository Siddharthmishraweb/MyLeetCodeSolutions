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
            if(a % 2 == 0 && a != 0){
                cout << a<<endl;
                minEven = min(minEven, a);
            }else if(a % 2 != 0 && a != 0){
                maxOdd = max(maxOdd, a);
            }
        }
        cout << "maxOdd: "<<maxOdd<<" ,"<<minEven<<endl;
        return maxOdd - minEven;
    }
};