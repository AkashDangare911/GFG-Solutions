//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    int solve(int n)
    {
        if(n<=6)
            return n;
            
        int recSum = solve(n/2)+solve(n/3)+solve(n/4);
        
        return max(n,recSum);
    }
    
    public:
    int maxSum(int n)
    {
        return solve(n);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends