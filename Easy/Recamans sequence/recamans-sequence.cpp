//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        vector<int> ans(n+1,0);
        unordered_set<int> s;
        s.insert(0);
        
        for(int i=1;i<=n;i++)
        {
            int cur = ans[i-1] - i;
            if(cur<0 || s.count(cur))
                cur = ans[i-1] + i;
            
            ans[i]=cur;
            s.insert(cur);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends