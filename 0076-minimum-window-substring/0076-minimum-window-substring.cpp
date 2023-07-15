class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> freq;
        string ans = "";
        int s_i = 0;
        for(int i = 0 ; i < t.size(); i++) freq[t[i]]++;

        int start = 0, current = 0, req = t.size();
        int min = INT_MAX;
        while(current < s.size()){
            if(freq.find(s[current]) != freq.end()){
                if(freq[s[current]] > 0)
                  req--;                
                freq[s[current]]--;

                while(req == 0){
                    int windowSize = current - start + 1;
                    if(min > windowSize){
                        min = windowSize;
                        s_i = start;
                        //ans = s.substr(start, windowSize);
                    }
                    if(freq.find(s[start]) != freq.end()){
                        freq[s[start]]++;
                        if(freq[s[start]] > 0){
                            req++;
                        }
                    }
                    start++;
                }
            }
            current++;
        }
        if(min == INT_MAX) return "";
        ans = s.substr(s_i, min);
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         if(s.size() == 1 && t.size() == 1){
//             if(s[0] == t[0]) return t;
//         }
//         unordered_map<char,int> freq, sFreq;
//         string ans = "";
//         bool flag = false;
//         for(int i = 0 ; i < t.size(); i++){
//             freq[t[i]]++;
//         }
//         int start = 0, current = 0, req = t.size();
//         int min = INT_MAX;
//         while(current < s.size()){
//             if(freq.find(s[current]) != freq.end() && freq[s[current]] > 0){
//                 freq[s[current]]--;
//                 req--;
//                 if(!flag){
//                     start = current;
//                     flag = true;
//                 }
//                 if(req == 0){
//                     if(min > current-start){
//                         int st = start == current && current != 0 ? current : current + 1;
//                         cout<<"start: "<<start<<" current: "<<current<<endl;
//                         ans = s.substr(start, st);
//                         min = current-start;
//                         req = t.size();
//                         for(int i = 0 ; i < t.size(); i++){
//                             freq[t[i]]++;
//                         }
//                         flag= false;
//                     }
//                 }
//             }
//             current++;
//         }
        
//         return ans;
    }
};