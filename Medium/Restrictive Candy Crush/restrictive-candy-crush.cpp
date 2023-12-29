//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string Reduced_String(int k,string s){
        stack<pair<char,int>> st;
        int n = s.size();
        int i=n-1;

        while(i>=0)
        {
            char c = s[i];

            // if char is not same as top
            if(st.empty() || st.top().first != c)
                st.push({c,1});
            else
                st.top().second++;

            // delete k elements
            if(st.top().second==k)
                st.pop();
            
            i--;
        }

        string ans="";
        while(!st.empty())
        {
           char c=st.top().first;
           int  n=st.top().second;

           for(int i=0;i<n;i++)
            ans.push_back(c);

            st.pop();
        }

        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    
    
    int t;cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.Reduced_String(k,s)<<"\n";
        
    }
    
	return 0;
}
// } Driver Code Ends