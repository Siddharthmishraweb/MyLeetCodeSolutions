class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,string> map ;
        map[1] = "I";
        map[4] = "IV";
        map[5] = "V";
        map[9] = "IX";
        map[10] = "X";
        map[40] = "XL";
        map[50] = "L";
        map[90] = "XC";
        map[100] = "C";
        map[400] = "CD";
        map[500] = "D";
        map[900] = "CM";
        map[1000] = "M";
        int arr[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        int n = num;
        string ans = "";
        for(int i = 0 ; i < 13 ; i++){
            while(arr[i] <= n){
                ans += map[arr[i]];
                n -= arr[i];
            }
        }
        return ans;
    }
};