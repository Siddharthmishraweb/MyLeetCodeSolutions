class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        int i =0 , j = 0;
        string ans ="";
        while(i < m  && j < n ){
            ans += word1[i];
            i++;
            ans += word2[j];
            j++;
        }
        while( i < m){
            ans += word1[i];
            i++;
        }
        while( j < n){
            ans += word2[j];
            j++;
        }
        
        return ans;
    }
};