//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        
        // if last 3 digs are divisible by 8, then number is divisible by 8
        
        int n=s.size();
        int num=0;
        
        if(n-3 >=0)
            num = (s[n-3]-'0');
        
        if(n-2 >=0)
            num = num*10+(s[n-2]-'0');
        
        if(n-1 >=0)
            num = num*10+(s[n-1]-'0');
            
        if(num%8 == 0)
            return 1;
        
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends