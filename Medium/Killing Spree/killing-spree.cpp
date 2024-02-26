//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    long long int killinSpree(long long int n)
    {
        long long int sum=0;
        long long int i=1;
        
        // 1 4 9 16
        // 
        while(sum<n)
        {
            if(sum+(i*i) == n)
            {
                return i;
            }
            else if(sum+(i*i) < n)
            {
                sum+=(i*i);
                i++;
            }
            else
                break;
        }
        
        return i-1;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n; cin>>n;
        Solution obj;
        long long int ans = obj.killinSpree(n);
        cout<<ans<<"\n";
    }
    return 0;
}

// } Driver Code Ends