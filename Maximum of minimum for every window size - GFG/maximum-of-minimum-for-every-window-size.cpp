//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    // 3 3 4 2 4   
    // 4 3 3 2 2

    vector <int> maxOfMin(int arr[], int n)
    {
       int right[n], left[n];
       vector<int> output;
       stack<int> st;
       stack<int> st2;
       // approch: find the next right minimum element from the current element.
       // : find the prev left minimum element from the current element.
       // right - left - 1 
       
       //populate right array
       for(int i = n-1 ; i >= 0 ; i--){
           while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
           right[i] = st.empty() ? n : st.top();
           st.push(i);
       }
       //populate leftStack
       for(int i = 0 ; i < n ; i++){
           while(!st2.empty() && arr[st2.top()] >= arr[i]) st2.pop();
           left[i] = st2.empty() ? -1 : st2.top();
           st2.push(i);
       }
       vector<int> out(n,INT_MIN);
       for(int i = 0 ; i < n ; i++){
           int length = right[i] - left[i] - 1;
           out[length-1] = max(arr[i],out[length-1]);
       }
       for(int i = n-2 ; i >= 0 ; i--){
           out[i] = max(out[i],out[i+1]);
       }
       return out;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends