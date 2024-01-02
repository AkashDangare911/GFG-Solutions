//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string s) {
        int arr[3]={0};
        int n=s.length();
        int i=0,j=0;
        int ans=n+1;
        
        while(j<n)
        {
            int c=s[j]-'0';
            arr[c]++;
            
            while(i<j && arr[0] && arr[1] && arr[2])
            {
                ans=min(ans,j-i+1);
                arr[s[i]-'0']--;
                i++;
            }
            
            j++;
        }
        
        if(ans==n+1)
            return -1;
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends