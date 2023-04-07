//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{

    public:
    bool contains(string a, string b){
        //cout<<a.length()<<" "<<b.length() <<endl;
        if(a.length() < b.length()) return false;
        for(int i = 0 ; i < a.length() ; i++){
            if(b[0] == a[i]){
                //cout<<"aa gye "<<a.substr(i,b.length())<<" , "<<b<<endl;
                string str = a.substr(i,b.length());
                if(str == b) return true;
            }
        }
        return false;
    }
    int repeatedStringMatch(string A, string B) 
    {
        string a = A,b=B;
        //if(b.length() > a.length()) return -1;
        int cnt = 1;
        string s = a;
        int newCnt = 0;
        while(!contains(a, b)){
             a += s;
            if(a.length() > b.length() && !contains(a,b)){
                newCnt++;
                if(newCnt > 10) return -1;
            }
            cnt++;
            if(cnt > 100000) break;
        }
       // cout<<cnt;
        return cnt > 100000 ? -1 : cnt;
    }
  
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution obj;
        cout<<obj.repeatedStringMatch(A,B)<<"\n";
    }
    return 0;
}

// } Driver Code Ends