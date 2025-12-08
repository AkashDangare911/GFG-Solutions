class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        vector<int> ans;
        int n=arr.size();
        
        for(int i=0;i<n;i++)
        {
            int cur = abs(arr[i]);
            
            if(arr[cur-1]<0)
                ans.push_back(cur);
            else
                arr[cur-1]=-1*arr[cur-1];
        }
        
        return ans;
    }
};