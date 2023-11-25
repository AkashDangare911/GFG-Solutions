//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	private:
	void helpme(int i,int j,int n,int arr[])
	{
	    if(j>=n)
	        return;
	        
	   int a = arr[i];
	   int b = arr[j];
	   
	   helpme(i+1,j+1,n,arr);
	   
	   arr[i*2]=a;
	   arr[(i*2)+1]=b;
	}
	
	public:
	void shuffleArray(int arr[],int n)
	{
        int i=0,j=n/2;
        
        helpme(i,j,n,arr);
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