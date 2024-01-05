//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int singleElement(int arr[] ,int n) 
    {
        int ans=0,count=0;
        
        for(int i=0;i<32;i++)
        {
            count=0;
            // check if i'th bit is set or not
            for(int j=0;j<n;j++)
            {
                if(((arr[j]>>i)&1)==1)
                    count++;
            }
            
            // if total set bits for cur pos is not multiple of 3, then the pos is 
            // gettting countributed by another number
            if(count%3 != 0)
                ans+=(1<<i);
        }
        
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends