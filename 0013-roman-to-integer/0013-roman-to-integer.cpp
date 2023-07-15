class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> map;
        map["I"] = 1;
        map["IV"] = 4;
        map["V"] = 5;
        map["IX"] = 9;
        map["X"] = 10;
        map["XL"] = 40;
        map["L"] = 50;
        map["XC"] = 90;
        map["C"] = 100;
        map["CD"] = 400;
        map["D"] = 500;
        map["CM"] = 900;
        map["M"] = 1000;
        
        int sum = 0;
       
        for(int i = 0 ; i < s.size() ; i++){
             string ans = "";
            ans += s[i];
            if(s[i] == 'I'){
                if(i+1 < s.length() && s[i+1] == 'V'){
                    ans += "V";
                    i++;
                }
                if(i+1 < s.length() && s[i+1] == 'X'){
                    ans += "X";
                    i++;
                }
            }
            if(s[i] == 'X'){
                if(i+1 < s.length() && s[i+1] == 'L'){
                    ans += "L";
                    i++;
                }
                if(i+1 < s.length() && s[i+1] == 'C'){
                    ans += "C";
                    i++;
                }
            }
            if(s[i] == 'C'){
                if(i+1 < s.length() && s[i+1] == 'D'){
                    ans += "D";
                    i++;
                }
                if(i+1 < s.length() && s[i+1] == 'M'){
                    ans += "M";
                    i++;
                }
            }
            sum += map[ans];
            ans = "";
        }
        return sum;
    }
};