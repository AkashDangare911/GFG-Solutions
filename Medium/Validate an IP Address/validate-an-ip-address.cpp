//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    bool checkValid(string s)
    {
        if(s.size()>3 || s.size()==0)
            return false;
            
        if(s[0]=='0' && s.size()!=1)
            return false;
            
        int n=0;
        
        for(char c:s)
        {
            if(c<'0' || c>'9')
                return false;
            n = n*10 + (c-'0');
        }
        
        if(n<0 || n>255)
            return false;
        
        return true;
    }
    
    public:
        int isValid(string s) {
            int i=0;
            int n=s.size();
            int num;
            int cnt=0;
            if(s[0]=='.' || s[n-1]=='.')
                return false;
            
            for(int i=0;i<n;i++)
            {
                string cur="";
                
                while(i<n && s[i]!='.')
                {
                    cur+=s[i];
                    i++;
                }
                
                if(checkValid(cur) == false)
                    return false;
                
                cnt++;
            }
            
            return cnt==4;
        }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends