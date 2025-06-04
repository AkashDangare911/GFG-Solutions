// User function Template for C++

class Solution {
  private:
    bool isPossible(int distance, vector<int> &arr, int k)
    {
        // we have to place k cows, out of which 1 cow would be placed 
        // at the starting point of array, means we have to find k-1 more points
        // hence returned true when k==1
        int leftStall=arr[0];
        int rightStall;
        
        for(int i=0;i<arr.size();i++)
        {
            rightStall=arr[i];
            
            if(rightStall-leftStall >= distance)
            {
                leftStall=rightStall;
                k--;
                
                if(k==1)
                    return true;
            }
        }
        
        return false;
    }
  public:
    int aggressiveCows(vector<int> &stalls, int k) {

        int n=stalls.size();
        int low=0, high=*max_element(stalls.begin(),stalls.end());
        int ans=-1;
        
        // distances were given in any order, so to get clear idea about distances, we sort
        sort(stalls.begin(),stalls.end());
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(isPossible(mid,stalls,k))
            {
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        
        return ans;
    }
};