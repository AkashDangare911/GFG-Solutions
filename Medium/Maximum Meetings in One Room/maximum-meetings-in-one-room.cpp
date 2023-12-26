//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> maxMeetings(int n,vector<int> &start,vector<int> &end)
    {
        // insert in reverse order
        // pair<pair<finish[i],start[i]>,index_of_meet>
        vector<pair<pair<int,int>,int>> arr;
        for(int i=0;i<n;i++)
            arr.push_back({{end[i],start[i]},i+1});
        
        sort(arr.begin(),arr.end());
        
        vector<int> ans;
        ans.push_back(arr[0].second);
        int j=1;
        int cur=arr[0].first.first;
        
        while(j<n)
        {
            if(cur < arr[j].first.second)
            {
                ans.push_back(arr[j].second);
                cur = arr[j].first.first;
            }
            
            j++;
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends