//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            vector<int> ans;
            int tSize = txt.size(),pSize=pat.size();
            
            // calculated ascii sum of pat
            int sum=0;
            for(int j=0;j<pSize;j++)
                sum+=pat[j];
                
            // using sliding window and checking the ascii sum
            int cur=0;
            int i=0,j=0;
            for(j=0;j<pSize;j++)
                cur+=txt[j];
                
    
            while(j<tSize)
            {
                if(cur==sum && (txt[i]==pat[0]))
                {
                    if(txt.substr(i,pSize)==pat)
                        ans.push_back(i+1);
                }
                
                cur+=txt[j];
                cur-=txt[i];
                i++,j++;
            }
            
            // for last index 
            if(cur==sum && (txt[i]==pat[0]))
            {
                if(txt.substr(i,pSize)==pat)
                    ans.push_back(i+1);
            }
            
            if(ans.size()==0)
                return {-1};
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
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends