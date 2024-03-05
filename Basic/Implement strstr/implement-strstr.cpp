//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}

// } Driver Code Ends


//Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x)
{
    int sn=s.size(),xn=x.size();
    if(xn>sn)
        return -1;
        
    for(int i=0;i<sn;i++)
    {
        if((s[i]==x[0]) && (sn-i >= xn))
        {
            int j=0,k=i;
            for(j=0;j<xn;j++)
            {
                if(s[k] != x[j])
                    break;
                
                k++;
            }
            
            if(j>=xn)
                return i;
        }
    }
    
    return -1;
}