//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int getSum(vector<vector<int>> mat,int i,int j,int n,vector<vector<int>> &dp)
    {
        if(i>=n)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int down = mat[i][j] + getSum(mat,i+1,j,n,dp);
        int l=INT_MIN,r=INT_MIN;
        
        if(j-1>=0)
            l = mat[i][j] + getSum(mat,i+1,j-1,n,dp);
        
        if(j+1<n)
            r = mat[i][j] + getSum(mat,i+1,j+1,n,dp);
            
        return dp[i][j]=max({down,l,r});
    }
    
public:
    int maximumPath(int n, vector<vector<int>> mat)
    {
        int ans=-1;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        dp[n-1]=mat[n-1];
       
        for(int i=n-2;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                int l=INT_MIN,r=INT_MIN;
                int down = mat[i][j]+dp[i+1][j];
                
                if(j-1>=0)
                    l = mat[i][j] + dp[i+1][j-1];
                    
                if(j+1<n)
                    r = mat[i][j] + dp[i+1][j+1];
                
                dp[i][j] = max({down,l,r});
            }
        }
        
        for(int i=0;i<n;i++)
        {
            ans = max(ans,dp[0][i]);
        }
        
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
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends