//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &matrix, int m, int n, int k)
    {
        vector<int> ans;
        int startRow = 0;
        int endRow = m-1;

        int startCol = 0;
        int endCol = n-1;

        int total = k;
        int count = 1;
        
        while(count <= total)
        {
            for(int i=startCol;count<=total && i<=endCol;i++){
                ans.push_back(matrix[startRow][i]);
                count++;
            }
            startRow++;

            for(int i=startRow;count<=total && i<=endRow;i++){
                ans.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--;

            for(int i=endCol;count<=total && i>=startCol;i--){
                ans.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--;

            for(int i=endRow;count<=total && i>=startRow;i--){
                ans.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++;
        }
        
        return ans.back();
    }

};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends