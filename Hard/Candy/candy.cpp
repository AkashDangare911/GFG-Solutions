//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCandy(int n, vector<int> &ratings) {
        // code here
        vector<int> arr(n,1);
        int ans=0;
        
        // forward loop
        for(int i=1;i<n;i++)
        {
            if(ratings[i] > ratings[i-1])
            {
                arr[i] = arr[i-1]+1;
            }
        }
        
        // backward loop
        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i] > ratings[i+1])
            {
                // if we already incremented in forward loop, then ignore
                // else increment the val
                if(arr[i] <= arr[i+1])
                {
                    arr[i] = arr[i+1]+1;
                }
            }
        }
        
        // calculate total sum of candies
        ans = accumulate(arr.begin(),arr.end(),0);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends