//User function template for C++

class Solution
{
    bool isPossible(vector<int> &arr, int painters,long long mid)
    {
        long long t=0;
        
        for(int i=0;i<arr.size();i++)
        {
            if(t+arr[i] <= mid)
            {
                t+=arr[i];
            }
            else
            {
                painters--;
                t=arr[i];
                
                if(painters==0 || t>mid)
                    return false;
            }
        }
        
        return true;
    }
    
  public:
    long long minTime(vector<int> arr, int k)
    {
        long long start=0, end=0;
        
        for(int i=0;i<arr.size();i++)
            end+=arr[i];
            
        while(start<end)
        {
            long long mid = start+(end-start)/2;
            
            if(isPossible(arr,k,mid))
                end = mid;
            else
                start = mid+1;
        }
        
        return start;
    }
};
