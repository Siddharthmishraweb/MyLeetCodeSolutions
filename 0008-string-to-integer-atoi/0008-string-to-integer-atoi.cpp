#define ll long long

class Solution {
public:
    int myAtoi(string s) {
        ll len = s.size();
        ll i = 0;
        double num = 0;
        while(s[i] == ' ') i++;
        bool pos = s[i] == '+';
        bool neg = s[i] == '-';
        pos || neg ? i++ : i;
        while(i < len && s[i] >= '0' && s[i] <= '9'){
            num = num * 10 + s[i] - '0';
            i++;
        }
        num = neg ? num * -1 : num;
        num = num > INT_MAX ? INT_MAX : num;
        num = num < INT_MIN ? INT_MIN : num;
        return (int)num;
    }
};