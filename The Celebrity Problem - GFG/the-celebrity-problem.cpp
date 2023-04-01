class Solution 
{
    public:
    //Brute Force
    int celebrity(vector<vector<int> >& M, int n) 
    {
        //BRUTE FORCE
        // vector<int> contender;
        // int zeroCnt = 0;
        // for(int i = 0 ; i < n ; i++){
        //     int cnt = 0;
        //     for(int j =  0; j < n ; j++){
        //         if(M[i][j] == 0) zeroCnt++;
        //         if(i != j){
        //             if(M[i][j] == 0){
        //                 cnt++;
        //             }
        //             if(cnt == n-1){
        //                 contender.push_back(i);
        //             }
        //         }
        //     }
        // }
        // for(int i = 0 ; i < contender.size() ; i++){
        //      int cnt = 0;
        //     for(int row = 0 ; row < n ; row++){
        //       int col = contender[i];
        //       if(row != col && M[row][col] == 1) cnt++;
        //       if(cnt == n - 1) return col;
        //     }
        // }
        // return -1;
        
        //OPTIMISED
        stack<int> st;
        for(int i = 0 ; i < n ; i++) st.push(i);
        
        while(st.size() > 1 ){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if(M[a][b] == 1)
              st.push(b);
            else
               st.push(a);
        }
        int potentialCandidate = st.top();
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            if(potentialCandidate != i){
                if(M[i][potentialCandidate] == 1) cnt++;
            }
        }
        // check if potential one is really potential if all are one in potenial row excet for potential itself
        int oneZero = 0;
        for(int i = 0 ; i < n ; i++){
            if(potentialCandidate != i){
                if(M[potentialCandidate][i] == 0) oneZero++;
            }
        }
        return oneZero == n - 1 && cnt == n - 1 ? potentialCandidate : -1;
    }
};


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
