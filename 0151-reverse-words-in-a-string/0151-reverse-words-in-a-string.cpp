class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> arr;
        while(ss >> word){
            arr.push_back(word);
        }
        string finalAns = "";
        for(int i = arr.size() - 1; i >= 0 ; i--){
            finalAns += arr[i];
            if(i != 0) finalAns += " ";
        }
        return finalAns;
    }
};