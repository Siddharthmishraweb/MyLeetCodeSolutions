class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> symBol;
        symBol["I"] = 1;
        symBol["V"] = 5;
        symBol["X"] = 10;
        symBol["L"] = 50;
        symBol["C"] = 100;
        symBol["D"] = 500;
        symBol["M"] = 1000;
        if(s.size() == 1){
            string newStr = "";
            newStr += s[0];
            return symBol[newStr];
        }
        int sumAns = 0;
        int index = 0;
        for(int i = 0 ; i < s.length() ; i++){
            if(i + 1 < s.length()){
                string ith = "",ith1 = "";
                ith += s[i];
                ith1 += s[i+1];
                int a = symBol[ith];
                int b = symBol[ith1];
                if(a < b) a =  -1 * a;
                sumAns += a;
                index = i;
            }
        }
        if(index < s.length()-1){
            index++;
            string newStr = "";
            newStr += s[index];
            sumAns += symBol[newStr];
        }
            
        cout<<index;
        return sumAns;
    }
};