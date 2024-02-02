//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    bool isValid(char c)
    {
        if(c>='0' && c<='9')
            return true;
        
        return false;
    }
    
  public:
    /*You are required to complete this method */
    int atoi(string s) 
    {
        bool neg=false;
        int n=s.size();
        int ans=0;
        if(s[0]=='-')
            neg=true;
        else
            ans = (s[0]-'0');
            
        for(int i=1;i<n;i++)
        {
            if(isValid(s[i]))
            {
                ans = ans*10 + (s[i]-'0');
            }
            else
            {
                ans=-1;
                neg=false;
                break;
            }
        }
        
        if(neg)
            ans *= -1;
            
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends