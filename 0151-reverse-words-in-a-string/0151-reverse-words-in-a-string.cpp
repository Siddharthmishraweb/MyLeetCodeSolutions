class Solution {
public:
    string removeExtraSpaces(string str){
        int index1 = 0,index2 = 0;
        for(int i = 0 ; i < str.size() ; i++){
            if(str[i] != ' '){ 
                index1 = i;
                break;
            }
        }
        for(int i = str.size() - 1; i >= 0 ; i--){
            if(str[i] != ' '){
                index2 = i;
                break;
            }
        }
        if(index2 == str.size() - 1) index2 = index2 + 1;
        return str.substr(index1,index2);
    }
    string reverseWords(string s) {
        int cntSpaces = 0;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == ' ') cntSpaces++;
        }
        if(cntSpaces == 0) return s;
        stack<string> st;
        string temp ="";
        int index = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] != ' ')temp += s[i];
            if(s[i] == ' '){
                if(temp.size() >= 1)
                 st.push(temp);
                temp = "";
                index = i;
            }
        }
        string norm = "";
        for(int i = index + 1 ; i < s.size() ; i++){
            if(s[i] != ' '){
                norm += s[i];
            }
        }
        if(index != 0){
            st.push(norm);
        }
        int size =st.size();
        string ansH="";
        for(int i = 0; i < size ; i++){
            ansH += st.top();
            if(i != size -1)
                ansH += " ";
            st.pop();
        }
        return removeExtraSpaces(ansH);
        //return ansH;
    }
};