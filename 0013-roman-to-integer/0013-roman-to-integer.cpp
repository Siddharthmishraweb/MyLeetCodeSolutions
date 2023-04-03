class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> symBol;
        symBol["I"] = 1;
        symBol["IV"] = 4;
        symBol["V"] = 5;
        symBol["IX"] = 9;
        symBol["X"] = 10;
        symBol["XL"] = 40;
        symBol["L"] = 50;
        symBol["XC"] = 90;
        symBol["C"] = 100;
        symBol["CD"] = 400;
        symBol["D"] = 500;
        symBol["CM"] = 900;
        symBol["M"] = 1000;
        int sumAns = 0;
        for(int i = 0 ; i < s.length() ; i++){
            int sum = 0;
            string ans = "";
            ans += s[i];
            if(s[i] == 'I'){
                if(i+1 < s.length() && s[i+1] == 'V'){
                    ans += 'IV';
                    i++;
                }else if(i+1 < s.length() && s[i+1] == 'X'){
                    ans += 'IX';
                    i++;
                }
            }
            if(s[i] == 'X'){
                if(i+1 < s.length() && s[i+1] == 'L'){
                    ans += 'XL';
                    i++;
                }else if(i+1 < s.length() && s[i+1] == 'C'){
                    ans += 'XC';
                    i++;
                }                
            }
            if(s[i] == 'C'){
                if(i+1 < s.length() && s[i+1] == 'D'){
                    ans += 'CD';
                    i++;
                }else if(i+1 < s.length() && s[i+1] == 'M'){
                    ans += 'CM';
                    i++;
                }                  
            }
            sumAns += symBol[ans];
            cout<<ans<<endl;
        }
        return sumAns;
    }
};