//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        long long ans=0;
        long long i=0,j=0;
        long long lsum=0,sum=0;
        
        while(j<k)
        {
            sum+=a[j];
            j++;
        }
        ans=sum;
        
        while(j<n)
        {
            sum+=a[j];
            lsum+=a[i];
            
            if(lsum<0)
            {
                sum-=lsum;
                lsum=0;
            }
            
            ans=max(ans,sum);
            
            j++;
            i++;
        }
        
        return ans;
    }
    // 5 -10 3 5 7
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends