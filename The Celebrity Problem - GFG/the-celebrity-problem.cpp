//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Brute Force
    int celebrity(vector<vector<int> >& M, int n) 
    {
        vector<int> contender;
        int zeroCnt = 0;
        for(int i = 0 ; i < n ; i++){
            int cnt = 0;
            for(int j =  0; j < n ; j++){
                if(M[i][j] == 0) zeroCnt++;
                if(i != j){
                    if(M[i][j] == 0){
                        cnt++;
                    }
                    if(cnt == n-1){
                        contender.push_back(i);
                    }
                }
            }
        }

        // cout<<"con are : "<<endl;
        // for(int i = 0 ; i < contender.size() ; i++) cout<<contender[i]<<", ";
        // cout<<endl<<":ended"<<endl;
        // all condenders we have
        for(int i = 0 ; i < contender.size() ; i++){
             int cnt = 0;
            for(int row = 0 ; row < n ; row++){
              int col = contender[i];
              if(row != col && M[row][col] == 1) cnt++;
              //cout<<"cnt: "<<cnt<<endl;
              if(cnt == n - 1) return col;
            }
        }
        return -1;
        if(zeroCnt == n* n) return -1;
        return contender.size() > 0 ? contender[0] : -1;;
    }
};




// 5
// 4
// 0 0 0 1
// 1 0 1 1
// 1 0 0 1
// 0 0 0 0
// 5
// 0 0 1 1 1
// 1 0 0 1 1
// 0 0 0 0 1
// 0 1 1 0 1
// 0 0 0 0 0
// 4
// 0 1 0 1
// 0 0 0 1
// 1 0 0 1
// 0 0 0 0
// 4
// 0 0 0 0
// 1 0 1 1
// 1 0 0 0
// 1 0 1 0
// 5
// 0 1 1 1 1
// 0 0 0 1 1
// 0 0 0 1 1
// 0 1 0 0 1
// 0 0 0 0 0

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends