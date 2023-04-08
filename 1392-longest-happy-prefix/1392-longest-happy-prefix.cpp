class Solution {
public:
    string longestPrefix(string s) {
        int lps[s.size()];
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
        for(int i = 0 ; i < s.size() ; i++){
            cout<<lps[i]<<" ";
        }
        string ans = "";
        for(int i = 0 ; i < lps[s.size() - 1] ; i++){
            ans += s[i];
        }
        return ans;
    }
};