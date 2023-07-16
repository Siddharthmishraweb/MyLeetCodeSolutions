//{ Driver Code Starts
// Program to find maximum guest at any time in a party
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> findMaxGuests(int Entry[], int Exit[], int N)
	{
	   int maxPeople = 0;
	   int activePeople = 0;
	   sort(Exit, Exit + N);
	   sort(Entry, Entry + N);
       int i = 0; 
       int j = 0;
       int ansTime = 0;
       while(i < N && j < N){
           int currentTime =  Exit[j];

           if(Entry[i] <= currentTime){
               activePeople++;
               if(maxPeople < activePeople){
                   maxPeople = activePeople;
                   ansTime = Entry[i];
               }
               i++;
           }else{
               activePeople--;
               j++;
           }
          // maxPeople = max(maxPeople, activePeople);
       }
       vector<int> out;
       
       out.push_back(maxPeople);
       out.push_back(ansTime);
	   return out;
	}

};

//{ Driver Code Starts.

 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        int entry[n],exit1[n];
        for(i=0;i<n;i++)
        cin>>entry[i];
        for(i=0;i<n;i++)
        cin>>exit1[i];
        Solution obj;

	    vector<int> p = obj.findMaxGuests(entry, exit1, n);
	    cout<<p[0]<<' '<<p[1];
	    cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends