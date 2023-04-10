class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> a, b;
        for(int i = 0 ; i < s.size() ; i++) a.push_back(s[i]);
        for(int i = 0 ; i < t.size() ; i++) b.push_back(t[i]);
        if(a.size() != b.size()) return false;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for(int i = 0 ; i < a.size(); i++){
            if(a[i] != b[i]) return false;
        }
        return true;
    }
};