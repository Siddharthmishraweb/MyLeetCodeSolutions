// #define ll long long
// class Solution {
// public:
//     // Brute Force
//     // vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
//     //     vector<int> out;
//     //     for(int i = 0 ; i < spells.size(); i++){
//     //         ll cnt = 0;
//     //         for(int j = 0 ; j < potions.size(); j++){
//     //             ll mul = (ll)spells[i] * (ll)potions[j];
//     //             if(mul >= success) cnt++;
//     //         }
//     //         out.push_back(cnt);
//     //     }
//     //     return out;
//     // }
    
//     // Optimised Solution Using Binary Aearch
//     vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
//         vector<int> ans;
//         for(int i = 0 ; i < spells.size() ; i++){
//             int mul = spells[i];
//             //use binary search
//             int low = 0, high = potions.size() - 1;
//             int mid = (low + high) / 2;
//             int index = 0;
//             while(low <= high){
//                 mid =  (low + high) / 2;
//                 if(mid * mul < success){
//                     index = mid;
//                     break;
//                 }
//                 else if(mid * mul > success){
//                     high = low;
//                 }
//             }
            
            
//             ans.push_back(index);
//             //return ans;
//         }
//         return ans;
//     }
// };



class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
       
        vector<int>ans;
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++){
            long long target = ceil(floor(success)/spells[i]);
            int index = lower_bound(potions.begin(),potions.end(),target) - potions.begin();
            ans.push_back(potions.size() - index);
        }
        return ans;
    }
};