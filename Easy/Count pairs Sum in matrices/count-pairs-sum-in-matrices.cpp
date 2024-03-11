//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	    // Your code goes here
	    int ans = 0;
        
        int i = 0;
        int j = 0;
        int l = n-1;
        int k = n-1;
        
        while( i < n && l >=0 )
        {
            int sum = mat1[i][j] + mat2[l][k];
            if(sum == x)
            {
                ans = ans+1;
                //j++;
                k = k-1;
            }
            else if(sum > x) k = k-1;
            else if(sum < x)j = j+1;
            
            if(j == n)
            {
                j = 0;
                i = i+1;;
            }
            
            if(k == -1)
            {
                k = n-1;
                l = l-1;
            }
        }
        
        return ans;
	}
};

//{ Driver Code Starts.


int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<vector<int>> mat1(n, vector<int>(n, -1));
        vector<vector<int>> mat2(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat1[i][j];
        	}
        }

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat2[i][j];
        	}
        }

        Solution ob;

        cout << ob.countPairs(mat1, mat2, n, x) << "\n";

    }

    return 0;
}
// } Driver Code Ends