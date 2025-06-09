// User function template for C++
class Solution {
  private:
    int firstIndex(vector<int> &arr)
    {
        int low=0, high=arr.size()-1;
        int mid;
        
        while(low<=high)
        {
            mid = (low+high)/2;
            
            if(arr[mid]==1)
                high=mid-1;
            else
                low=mid+1;
        }
        
        return low;
    }
    
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int m = arr.size(), n=arr[0].size();
        int row=-1, ans=0;
        
        for(int i=0;i<m;i++)
        {
            int ind = firstIndex(arr[i]);
            int ones = n-ind;
            
            if(ones>ans)
            {
                row=i;
                ans=ones;
            }
        }
        
        return row;
    }
};