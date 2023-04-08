class Solution {
public:
    
    void lpsGenerator(string s, int* lps){
        // int lps[s.size()];
        lps[0] = 0;
        int len = 0;
        for(int i = 1 ; i < s.size() ; i++){
            if(s[len] == s[i]){
                len++;
                lps[i] = len;
            }else{
               if(len == 0) lps[i] = 0;
               else{
                   len = lps[len-1];
                   i--;
               }
            }
        }        
    }
    int strStr(string haystack, string needle) {
        int ans =-1;
        //using KMP Algo
        int size = needle.size();
        int n = haystack.size();
        int lps[size];
        lpsGenerator(needle,lps);
        int i = 0 , j = 0;
        while(i < n){
            if(haystack[i] == needle[j]){
                i++;
                j++;
                if(j == size){
                    // j = lps[j-1];
                    ans =  i - j;
                    j = lps[j-1];
                    break;
                }
            }else if(i < n ){
                if(j == 0) i++;
                else j = lps[j-1];
            }
        }
        
        // for(int i = 0 ; i < haystack.size() ; i++){
        //     if(haystack.substr(i,size) == needle)
        //         return i;
        // }
         return ans;
    }
};