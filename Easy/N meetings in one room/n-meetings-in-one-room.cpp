//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    static bool cmp(pair<int,int> a,pair<int,int> b)
    {
        if(a.second < b.second)
            return true;
        return false;
    }
    
    public:
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> meets;
        for(int i=0;i<n;i++)
            meets.push_back({start[i],end[i]});
        sort(meets.begin(),meets.end(),cmp);        // sort on based on short endTime
            
            
        // check if endTime of current meet is more than prev or not
        int endTime=meets[0].second;
        int cnt=1;
        for(int i=1;i<n;i++)
        {
            if(meets[i].first > endTime)
            {
                cnt++;
                endTime=meets[i].second;
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends