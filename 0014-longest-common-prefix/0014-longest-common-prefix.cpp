#define ll long long
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        ll len = INT_MAX,index = 0;
        string str = "";
        for(int i = 0 ; i < strs.size() ; i++){
            if(strs[i].size() < len){
                len = strs[i].size();
                str = strs[i];
                index =i;
            }
        }
        int cnt = 0;
        bool isValid = true;
        for(int i = 0 ; i < str.size() ; i++){
            for(int j = 0 ; j < strs.size() ; j++){
                if(j == index) continue;
                if(strs[j][i] != str[i]){
                    isValid = false;
                }
            }
            if(isValid){
                cnt++;
            }else break;
        }
        return cnt == 0 ? "" : str.substr(0,cnt);

    }
};