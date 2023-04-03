class Solution {
public:
    void check(int& start, int& end, string s,int &maxi, int& index){
        while((start >= 0 && end < s.length() )&&  s[start] == s[end]){
            if(end - start + 1 > maxi){
                maxi = end - start + 1;
                index = start;
            }
            start--;
            end++;
        }        
    }
    string longestPalindrome(string s) {
        if(s.size()==1) return s;
        //for odd length
        int maxi = 1,index = 0;
        int maxi2 = 1, index2 = 0;
        for(int i = 0 ; i < s.length() ; i++){
            int start = i - 1;
            int end = i + 1;
            int len = 1;
            
            check(start,end,s,maxi,index);
            start = i;
            end = i + 1;
            check(start,end,s,maxi2,index2);
        }
        if(maxi < maxi2){
            index = index2;
            maxi = maxi2;
        }
        return s.substr(index, maxi);
    }
};