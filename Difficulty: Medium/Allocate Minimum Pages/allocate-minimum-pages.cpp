class Solution {
  private:
    bool canAllocate(vector<int> &arr, int k, int mid)
    {
        int sum=0;
        
        for(int n:arr)
        {
            if(n>mid)
                return false;
            
            if(sum+n > mid)
            {
                k--;
                sum=0;
            }
            sum+=n;
        }
        return k>0;
    }
    
  public:
    int findPages(vector<int> &arr, int k) {
        int n=arr.size();
        // not possible case
        if(k>n)
            return -1;
            
        int st=0, en=accumulate(arr.begin(),arr.end(),0);
        int mid;
        
        while(st<en)
        {
            mid = (st+en)/2;
            
            if(canAllocate(arr,k,mid))
                en=mid;
            else
                st=mid+1;
        }
        
        return st;
    }
};