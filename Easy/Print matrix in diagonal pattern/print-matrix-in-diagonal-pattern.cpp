//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         //Your code here
        int row=0, col=0, n = mat.size();
        vector<int> ans;
        bool right = true;
        
        while(row < n && col < n) {
            ans.push_back(mat[row][col]);
            
            if(right) {
                if(row-1 >= 0 && col+1 < n) {
                    row--; col++;
                } else {
                    right = false;
                    col+1 < n ? col++ : row++;
                }
            } else {
                if(col-1 >= 0 && row+1 < n) {
                    col--; row++;
                } else {
                    right = true;
                    row+1 < n ? row++ : col++;
                }
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends