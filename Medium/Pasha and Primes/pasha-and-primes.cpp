//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    bool isPrime(int n)
    {
        if(n<2)
            return false;
            
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
                return false;
        }
        
        return true;
    }
    
  public:
    vector<int> primeRange(int n, int q, vector<int> a,
                           vector<pair<int, int>> r) {
        // code here
        vector<int> ans;
        unordered_map<int,int> mp;
        int nos=0;
        
        for(int i=0;i<n;i++)
        {
            if(isPrime(a[i]))
                nos++;
            mp[i]=nos;
        }
        // 1 2 3 4 5
        
        for(int i=0;i<q;i++)
        {
            int total=0;
            total+= mp[r[i].second-1];
            total-= mp[r[i].first-1];
            
            if(isPrime(a[r[i].first-1]))
                total++;
            
            ans.push_back(total);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, Q;
        cin >> N >> Q;
        vector<int> A(N);
        vector<pair<int, int>> R(Q);
        for (int i = 0; i < N; i++) cin >> A[i];
        for (int i = 0; i < Q; i++) cin >> R[i].first >> R[i].second;
        Solution ob;
        vector<int> ans = ob.primeRange(N, Q, A, R);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends