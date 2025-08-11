class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int n=s.size();
        int l=0,r=0;
        int ans=0;
        unordered_map<int,int> mp;
        
        while(r<n)
        {
            char c=s[r];
            
            // in case, if any element occurs again, but left has moved forward,
            // take the left
            // if not, then take the prev position of the element & move left further by 1
            if(mp.count(c))
            {
                l=max(l,mp[c]+1);
            }
            
            mp[c]=r;
            ans=max(ans,r-l+1);
            r++;
        }
        
        return ans;
    }
};
