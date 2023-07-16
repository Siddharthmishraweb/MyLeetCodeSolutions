//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int houseRobber(int arr[], int dp[], int n){
       if(n == 0) return 0;
       if(n == 1) return arr[0];
       if(n == 2) return max(arr[0], arr[1]);
       
       if(dp[n] != -1)
         return dp[n];
       
       dp[n] =  max(arr[0] + houseRobber(arr+2,dp, n - 2), houseRobber(arr+1,dp, n - 1));
       return dp[n];
    }
    int FindMaxSum(int arr[], int n)
    {
        int dp[n+1];
        for(int i = 0 ; i < n+1; i++) dp[i] = -1;
        houseRobber(arr, dp, n);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends