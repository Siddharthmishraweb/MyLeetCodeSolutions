class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '{' || s[i] == '(' || s[i] == '['){
                st.push(s[i]);;
            }else{
                if(st.empty()) return false;
                if(st.top() == '(' && s[i] != ')') return false;
                if(st.top()== '{' && s[i] != '}') return false;
                if(st.top() == '[' && s[i] != ']') return false;
                if(!st.empty())st.pop();
                //return true;
            }
        }
        return st.size() == 0? true:false;
    }
};