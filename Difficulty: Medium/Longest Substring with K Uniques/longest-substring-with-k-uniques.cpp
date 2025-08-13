class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n=s.size();
        int left=0, right=0;
        int ans=-1;
        unordered_map<char,int> mp;

        while(right<n)
        {
            char c=s[right];
            mp[c]++;
            
            while(mp.size()>k)
            {
                mp[s[left]]--;
                if(mp[s[left]]==0)
                    mp.erase(s[left]);
                
                left++;
            }

            if(mp.size()==k)
                ans=max(ans,right-left+1);

            right++;
        }

        return ans;
        
    }
};