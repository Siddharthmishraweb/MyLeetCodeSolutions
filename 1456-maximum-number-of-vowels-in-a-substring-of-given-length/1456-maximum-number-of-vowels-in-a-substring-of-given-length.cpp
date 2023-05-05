class Solution {
public:
    int maxVowels(string s, int k) {
        int maxiVovel = 0;
        int n = s.size();
        int arr[n];
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == 'a' || s[i]== 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                maxiVovel++;
            }
            arr[i] = maxiVovel;
        }
        int maxi = 0;
        for(int i = k-1 ; i < n ; i++){
            if(i == k - 1){
                maxi = max(maxi, arr[i]);
            }
            else{
                maxi = max(maxi, arr[i] - arr[i-k]);
            }
        }
        return maxi;
    }
};