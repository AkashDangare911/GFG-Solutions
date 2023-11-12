//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string s1, string s2)
    {
        if(s1.size() != s2.size())
            return false;
            
        int n=s1.size();
        if(n==1 || n==2)
            return s1==s2;
        
            
        string temp1 = "";
        temp1+= s2[n-2];
        temp1+= s2[n-1];
        temp1+=s2.substr(0,n-2);
        
        if(temp1==s1)
            return true;
            
        string temp2 = "";
        temp2+=s2.substr(2,n);
        temp2+= s2[0];
        temp2+= s2[1];
        
        
        return temp2==s1;
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends