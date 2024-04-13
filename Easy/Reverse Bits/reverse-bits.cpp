//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long x) {
        long long ans=0;
        string temp(32,'0');
        int n=31;
        
        while(x)
        {
            if(x&1)
                temp[n]='1';
            else
                temp[n]='0';
            
            n--;
            x=x>>1;
        }
        
        
        long long mul=1;
        for(char c:temp)
        {
            if(c=='1')
                ans+=mul;
            
            mul*=2;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends