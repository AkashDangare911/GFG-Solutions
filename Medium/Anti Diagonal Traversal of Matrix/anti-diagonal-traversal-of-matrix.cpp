//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        // Code here
        vector<int> ans;
        vector<int> half;
        int n = matrix.size();
        
        // first row traverse
        for(int i=0;i<n;i++)
        {
            int temp=0;
            
            for(int j=i;j>=0;j--)
            {
                ans.push_back(matrix[temp++][j]);
            }
        }
        
        int j_pos=n-1;
        // reverse last row traverse
        for(int i=n-1;i>0;i--)
        {
            int temp=n-1;
            
            for(int j=j_pos;j<n;j++)
            {
                half.push_back(matrix[temp--][j]);
            }
            j_pos--;
        }
        
        for(int i=half.size()-1;i>=0;i--)
            ans.push_back(half[i]);
        
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