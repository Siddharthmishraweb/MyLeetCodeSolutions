class Solution {
public:
    int strStr(string haystack, string needle) {
        int size = needle.size();
        for(int i = 0 ; i < haystack.size() ; i++){
            if(haystack.substr(i,size) == needle)
                return i;
        }
        return -1;
    }
};