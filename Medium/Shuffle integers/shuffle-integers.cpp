//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	
	public:
	void shuffleArray(int arr[],int n)
	{
	    // Your code goes here
	    int dup[n]={0};
	    int cur=0;
	    
	    for(int i=0;i<n;i+=2)
	    {
	        dup[i]=arr[cur];
	        cur++;
	    }
	    
	    cur=n/2;
	    
	    for(int i=1;i<n;i+=2)
	    {
	        dup[i]=arr[cur];
	        cur++;
	    }
	    
	    for(int i=0;i<n;i++)
	        arr[i]=dup[i];
	}
		 

};

//{ Driver Code Starts.


int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin>>n;
	    int a[n] ;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }


       

        Solution ob;
        ob.shuffleArray(a, n);

		for (int i = 0; i < n; i++) 
			cout << a[i] << " ";
    
	
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends