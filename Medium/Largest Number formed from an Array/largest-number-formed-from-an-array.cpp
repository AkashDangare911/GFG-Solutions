//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
private:

    static bool custom_cmp(string a,string b)
    {
        if(a+b > b+a)
            return true;
        
        return false;
    }
    
public:

	string printLargest(vector<string> &arr) {
	    int n = arr.size();
	    string ans="";
	    
	    sort(arr.begin(),arr.end(),custom_cmp);
	    
	    
	    for(int i=0;i<n;i++)
	        ans+=arr[i];
	        
	    return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends