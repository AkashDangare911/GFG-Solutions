//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    void help1(int n,vector<int> &ans)
    {
        if(n<=0)
        {
            ans.push_back(n);
            return;
        }
        
        ans.push_back(n);
        n-=5;
        help1(n,ans);
    }
    
    void help2(int n,int cur,vector<int> &ans)
    {
        if(cur<n)
        {
            cur+=5;
            ans.push_back(cur);
            help2(n,cur,ans);
        }
    }
    
public:
    vector<int> pattern(int N){
        vector<int> ans;
        
        help1(N,ans);
        help2(N,ans.back(),ans);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends