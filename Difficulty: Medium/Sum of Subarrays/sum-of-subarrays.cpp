class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        int ans=0;
        int n=arr.size();
        
        for(int i=0;i<n;i++)
        {
            int starting_choises = i+1;
            int ending_choises = n-i;
            int cur = starting_choises*ending_choises*arr[i];
            ans+=cur;
        }
        
        return ans;
    }
};