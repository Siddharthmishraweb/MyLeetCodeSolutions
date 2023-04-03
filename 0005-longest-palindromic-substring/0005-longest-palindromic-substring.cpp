class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==1) return s;
        //for odd length
        int maxi = 1,index = 0;
        for(int i = 1 ; i < s.length() ; i++){
            int start = i - 1;
            int end = i + 1;
            int len = 1;
            while((start >= 0 && end < s.length() )&&  s[start] == s[end]){
                if(end - start + 1 > maxi){
                    maxi = end - start + 1;
                    index = start;
                }
                start--;
                end++;
            }
        }
        int maxi2 = 1, index2 = 0;
        //for odd length
        for(int i = 0 ; i < s.length() ; i++){
            int start = i;
            int end = i + 1;
            while((start >= 0 && end < s.length() )&&  s[start] == s[end]){
                if(end - start + 1 > maxi2){
                    maxi2 = end - start + 1;
                    index2 = start;
                }
                start--;
                end++;
            }
        }
        if(maxi < maxi2){
            index = index2;
            maxi = maxi2;
        }
        return s.substr(index, maxi);
    }
};