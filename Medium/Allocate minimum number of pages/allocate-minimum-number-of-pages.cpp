//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    private:
    bool isPossible(int arr[], int n, int m,int mid)
    {
        int student=1;
        int allocatedPages=0;
        
        for(int i=0;i<n;i++)
        {
            // include current pages if possible
            if(allocatedPages+arr[i] <= mid)
            {
                allocatedPages+=arr[i];
            }
            else
            {
                // otherwise increase student count, and check constrains
                student++;
                
                allocatedPages=0;
                allocatedPages=arr[i];
                
                // we are not able to form ans with given mid, if
                // 1.student-count is more than expected 
                // 2.pages in book are larger than currently distributing i.e. mid
                if(student>m || allocatedPages>mid)
                    return false;
                    
            }
        }
        
        return true;
    }
    
    public:
    int findPages(int arr[], int n, int m) 
    {
        if(n<m)
            return -1;
            
        int ans=-1;
        int start=0;
        int end=0;      //take end as sum of all elements of array
        
        for(int i=0;i<n;i++)
            end+=arr[i];
        
        int mid = start+(end-start)/2;
        
        while(start<=end)
        {
            // if we allocate large no. of pages, then ans is possible
            // hence reduce search space by decreasing end to mid-1
            if(isPossible(arr,n,m,mid))
            {
                ans=mid;
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
            
             mid = start+(end-start)/2;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends