//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    int low[26]={0};
	    int upp[26]={0};
	    string ans="";
	    
	    for(char c:str)
	    {
	       // uppercase letters
	        if(c>='A' && c<='Z')
	        {
	            if(upp[c-'A']==0)
	                ans+=c;
	               
	            upp[c-'A']++;
	        }
	       // lowercase letters
	        else
	        {
	            if(low[c-'a']==0)
	                ans+=c;
	               
	            low[c-'a']++;
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
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends