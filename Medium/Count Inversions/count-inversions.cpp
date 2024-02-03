//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    long long merge(long long arr[], long long l, long long m, long long r)
    {
        long long i=l,j=m+1;
        // long long temp[r+1];
        vector<long long> temp;
        // int k=0;
        long long cnt=0;
        
        while(i<=m && j<=r)
        {
            if(arr[i]<=arr[j])
            {
                // temp[k]=arr[i];
                temp.push_back(arr[i]);
                i++;
            }
            else
            {
                // temp[k]=arr[j];
                temp.push_back(arr[j]);
                cnt+=(m-i+1);
                j++;
            }
            // k++;
        }
        
        while(i<=m)
        {
            // temp[k++]=arr[i++];
            temp.push_back(arr[i++]);
        }
        
        while(j<=r)
        {
            temp.push_back(arr[j++]);
            // temp[k++]=arr[j++];
        }
        
        // k=0;
        for(long long z=l;z<=r;z++)
        {
            arr[z]=temp[z-l];
            // k++;
        }
        
        return cnt;
    }
    
    long long mergeSort(long long arr[], long long l, long long r)
    {
        long long cnt=0;
        
        if(l<r)
        {
            long long mid = (l+r)/2;
            cnt += mergeSort(arr,l,mid);
            cnt += mergeSort(arr,mid+1,r);
            
            cnt += merge(arr,l,mid,r);
        }
        
        return cnt;
    }
    
  public:
    long long int inversionCount(long long arr[], long long n)
    {
        long long ans =  mergeSort(arr,0,n-1);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends