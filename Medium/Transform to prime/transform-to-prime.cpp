//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    private:
    bool isPrime(int n)
    {
        if(n<2)
            return false;
            
        int sq = sqrt(n);
        
        for(int i=2;i<=sq;i++)
        {
            if((n%i)==0)
                return false;
        }
        
        return true;
    }
    
    public:
    int minNumber(int arr[],int n)
    {
        int sum = 0;
        for(int i=0;i<n;i++)
            sum+=arr[i];
            
        int i=sum;
        
        while(!isPrime(i))
        {
            i++;
        }
        
        return i-sum;
    }
};


//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends