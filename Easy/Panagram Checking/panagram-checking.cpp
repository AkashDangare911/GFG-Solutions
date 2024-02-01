//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
    bool isValid(char c)
    {
        if((c>='a' && c<='z') || (c>='A' && c<='Z'))
            return true;
        return false;
    }
    
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        int arr[26]={0};
        
        for(int i=0;i<s.size();i++)
        {
            char c=s[i];
            
            if(isValid(c))
            {
                if(c<'a'){
                    arr[c-'A']++;
                }
                else
                {
                    arr[c-'a']++;
                }
            }
        }
        
        
        for(int i=0;i<26;i++)
        {
            if(arr[i]==0)
                return false;
        }
        
        return true;
    }

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends