//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    // code here
	   // pen paper intuition gives rise to fib series
	   if(n<=2)
	        return n+1;
	        
	    int mod = 1e9 +7;
        ll a =2;
        ll b =3;
        ll third=0;
        
        for(int i=2;i<n;i++)
        {
            third = (a+b)%mod;
            a = b;
            b = third;
        }
        
        return third;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends