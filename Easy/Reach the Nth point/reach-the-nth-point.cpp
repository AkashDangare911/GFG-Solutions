//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		int nthPoint(int n){
		    // Code here
		    if(n <= 2)
		        return n;
		        
		    int first = 1,second = 2;
		    int third=0;
		    int mod = 1e9+7;
		    
		    for(int i=2;i<n;i++)
		    {
		        third = (first+second)%mod;
		        
		        first = (second)%mod;
		        second = (third)%mod;
		    }
		    
		    return third;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends