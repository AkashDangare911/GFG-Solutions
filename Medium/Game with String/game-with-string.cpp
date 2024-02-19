//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        int arr[26]={0};
        for(char c:s)
            arr[c-'a']++;
        
        // 3 4 5
        priority_queue<int> pq;
        for(int i=0;i<26;i++)
        {
            if(arr[i])
                pq.push(arr[i]);
        }
        
        while(k)
        {
            int t = pq.top();
            pq.pop();
            if(t>1)
                pq.push(t-1);
            k--;
        }
        
        int ans=0;
        while(!pq.empty())
        {
            int t = pq.top();
            // cout<<t<<" ";
            ans+=(t*t);
            pq.pop();
        }
        // cout<<endl;
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends