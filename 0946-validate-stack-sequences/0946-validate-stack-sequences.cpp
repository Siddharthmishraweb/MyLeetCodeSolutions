class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        st.push(pushed[0]);
        int n = popped.size();
        int j = 1;
        for(int i = 0 ; i < n ; i++){ 
            if(st.empty()){
                st.push(pushed[j]);
                j++;
            }
            while(!st.empty() && popped[i] != st.top() && j < pushed.size()){
                st.push(pushed[j]);
                j++;
            }
            while(!st.empty() && popped[i] == st.top()) st.pop();
        }
        return st.empty();
    }
};