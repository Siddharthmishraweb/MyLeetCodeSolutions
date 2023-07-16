//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        int numLessThank = 0, ans = INT_MAX;
        for(int i = 0 ; i < n ; i++)
            if(arr[i] <= k) numLessThank++;
        int bad = 0;
        for(int i = 0 ; i < numLessThank ; i++){
            if(arr[i] > k) bad++;
        }
        
        int i = 0, j = numLessThank - 1;;
        while(i < n && j < n){
           
                ans = min(ans, bad);
                j++;
                if(arr[j] > k) bad++;
                if(arr[i] > k) bad--;
                i++;

        }
        return ans;
    }
};

// class Solution {
// public:
//     int minSwap(int arr[], int n, int k) {
//         int numLessThanK = 0, ans = INT_MAX;
//         for (int i = 0; i < n; i++) {
//             if (arr[i] <= k) numLessThanK++;
//         }
        
//         int bad = 0;
//         int i = 0, j = numLessThanK - 1;
        
//         // Count the initial number of "bad" elements in the first window
//         for (int x = i; x <= j; x++) {
//             if (arr[x] > k) bad++;
//         }
        
//         ans = min(ans, bad);
        
//         while (j < n - 1) {
//             // Move the window
//             i++;
//             j++;
            
//             // Update the "bad" count based on the new elements in the window
//             if (arr[j] > k) bad++;
//             if (arr[i - 1] > k) bad--;
            
//             // Update the answer
//             ans = min(ans, bad);
//         }
        
//         return ans;
//     }
// };




//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends