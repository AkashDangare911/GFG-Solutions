//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) 
    {
        int ans=INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            if(a[i]==x)
            {
                int ind=i-1;
                int l=1e6,r=1e6;
                
                while(ind>=0 && a[ind]!=y)
                    ind--;
                
                if(ind>=0)
                    l = i-ind;
                    
                ind=i+1;
                while(ind<n && a[ind]!=y)
                    ind++;
                
                if(ind<n)
                    r = ind-i;
                
                if(l==1e6 && r==1e6)
                    return -1;
                    
                ans = min(ans,min(l,r));
            }
        }
        
        if(ans==INT_MAX)
            return -1;
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends