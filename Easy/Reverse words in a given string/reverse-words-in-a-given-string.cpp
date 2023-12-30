//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        int n=s.size();
        reverse(s.begin(),s.end());
        int i=0,j=0;
        
        while(j<n)
        {
            // traverse till dot
            while(j<n && s[j] != '.')
                j++;
            
            // reverse each word
            int k=j-1;
            while(i<k)
            {
                swap(s[i],s[k]);
                i++,k--;
            }
            
            j++;
            i=j;
        }
        
        return s;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends