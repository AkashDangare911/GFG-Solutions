//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    private:
    void solve(vector<int> a, int i,int n, vector<int> temp, vector<vector<int>> &ans)
    {
        if(i>=n)
        {
            ans.push_back(temp);
            return;
        }
        
        // include
        temp.push_back(a[i]);
        solve(a,i+1,n,temp,ans);
        temp.pop_back();
        
        // exclude
        solve(a,i+1,n,temp,ans);
    }
    
    public:
    vector<vector<int> > subsets(vector<int>& a)
    {
        vector<vector<int> > ans;
        vector<int> temp;
        int index=0;
        int n=a.size();
        
        solve(a,index,n,temp,ans);
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}
// } Driver Code Ends