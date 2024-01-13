//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        vector<int> ans;
        map<vector<int>, vector<int>> mp;
        int i=0;
        
        for(vector<int> v:matrix)
        {
            mp[v].push_back(i);
            i++;
        }
        
        for(pair<vector<int>,vector<int>> p:mp)
        {
            int n = p.second.size();
            
            for(int i=1;i<n;i++)
                ans.push_back(p.second[i]);
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



// } Driver Code Ends