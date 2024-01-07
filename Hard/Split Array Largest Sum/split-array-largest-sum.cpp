//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    bool isPossible(int arr[],int n,int k,int sum)
    {
        int temp=0;
        int cnt=1;
        
        for(int i=0;i<n;i++)
        {
            if(temp+arr[i]>sum)
            {
                // if element is larger, then we can't divide the arr feasibly
                if(arr[i]>sum)
                    return false;
                // k--;
                cnt++;
                temp=arr[i];
            }
            else
                temp+=arr[i];
        }
        
        return cnt<=k;
    }
    
  public:
    int splitArray(int arr[] ,int n, int k) {
        int ans=-1;
        int st=1,en=accumulate(arr,arr+n,0);
        
        while(st<=en)
        {
            int mid = (st+en)/2;
            
            if(isPossible(arr,n,k,mid))
            {
                ans=mid;
                en=mid-1;
            }
            else
                st=mid+1;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends