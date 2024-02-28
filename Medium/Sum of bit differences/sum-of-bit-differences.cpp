//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	long long sumBitDifferences(int arr[], int n) {
	    long long ans=0;
	    long long bits[32]={0};
	    
	    for(int i=0;i<n;i++)
	    {
	        int num = arr[i];
	        int ind=31;
	        
	        while(num)
	        {
	            if(num&1)
	                bits[ind]++;
	               
	           ind--;
	           num=num>>1;
	        }
	    }
	    
	    for(int i=31;i>=0;i--)
	    {
	        ans+=(bits[i]*(n-bits[i]));
	    }
	    
	    return ans*2;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumBitDifferences(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends