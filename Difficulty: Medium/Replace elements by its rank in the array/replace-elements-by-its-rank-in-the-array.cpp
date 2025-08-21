// User function Template for C++

class Solution {
  public:

    vector<int> replaceWithRank(vector<int> &arr, int n) {
       // sort the arr, to store ranks of each no.
        unordered_map<int,int> mp;
        vector<int> ans(arr.begin(),arr.end());
        sort(arr.begin(),arr.end());

        // store ranks in map, avoid duplicate elements
        int rank=1;
        for(int i=0;i<n;i++)
        {
            if(!mp[arr[i]])
            {
                mp[arr[i]]=rank;
                rank++;
            }
        }

        // find ranks from map
        for(int i=0;i<n;i++)
            ans[i]=mp[ans[i]];

        return ans;
    }
};
