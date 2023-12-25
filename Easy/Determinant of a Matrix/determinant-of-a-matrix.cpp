//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    int determinantOfMatrix(vector<vector<int> > matrix, int n)
    {
        if(n == 1) 
            return matrix[0][0];
            
        int det = 0;
        
       //traverse first row 
       for(int i = 0; i<n; i++)
       {
           //find the submatrix after ignoring the first row and i'tH column
           vector<vector<int> > subMat(n-1 , vector<int>(n-1));
           
           for(int j = 1; j<n; j++) //for traversing the row except first row
           {
               int x = 0;
               for(int k = 0; k<n; k++) //kTH column of jth row and skip the kth col if i==k
               {
                   if(i == k) 
                        continue;
                   subMat[j-1][x++] = matrix[j][k];
               }
           }
           
           det += matrix[0][i]*determinantOfMatrix(subMat , n-1)*(i&1 ? -1:1);
       }
       return det;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        int result = ob.determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    }
    return 0;
}
// } Driver Code Ends