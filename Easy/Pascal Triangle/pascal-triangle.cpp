//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<long long> nthRowOfPascalTriangle(int n) {
       
        vector<vector<long long>> ans;
        ans.push_back({1});
        int mod=1e9+7;
        
        for(int i=1;i<n;i++)
        {
            vector<long long> temp = ans[ans.size()-1];
            vector<long long> cur;
            
            for(int j=0;j<=temp.size();j++)
            {
                if((j==0) || (j==temp.size()))
                    cur.push_back(1);
                else
                    cur.push_back((temp[j]+temp[j-1])%mod);
            }
            
            ans.push_back(cur);
        }
        
        return ans[ans.size()-1];
    }
};


//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends