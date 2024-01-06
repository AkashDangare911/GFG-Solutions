//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalWays(int n)
	{
	   // no of ways to construct buildings on left are independent of right side
	   //so, if we  can construct with 5 ways on left, the same no. will be on right side
	   //so we find no of ways to construct on left and square it
	   
	   //no of ways to construct on each side, is the nth fibo number
	   
	   long mod = 1e9+7;
	   long dp[n+1]={0};
	   dp[1]=2;
	   dp[2]=3;
	   
	   for(int i=3;i<=n;i++)
	    dp[i]=(dp[i-1]+dp[i-2])%mod;
	    
	    
	   //squared the ways to build
	   int ans = (dp[n]*dp[n])%mod;
	   
	   return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends