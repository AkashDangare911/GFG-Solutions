//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        // approach here is to gather all edge element pairs, for further traversals
        vector<pair<int,int>> indexes;
        vector<int> ans;
        int n = matrix.size();
        
        // first row traverse
        for(int i=0;i<n;i++)
            indexes.push_back({0,i});
        
        // last col traverse
        for(int i=1;i<n;i++)
            indexes.push_back({i,n-1});
        
        for(pair<int,int> p:indexes)
        {
            int row=p.first;
            int col=p.second;
            
            while(row<n && col>=0)
            {
                ans.push_back(matrix[row][col]);
                row++;
                col--;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends