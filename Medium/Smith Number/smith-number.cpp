//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
private:
    int sumOfDigs(int n)
    {
        int ans=0;
        while(n)
        {
            ans+=n%10;
            n = n/10;
        }
        
        return ans;
    }
    
    bool isPrime(int n)
    {
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
                return false;
        }
        
        return true;
    }
  public:
    int smithNum(int n) {
        
        int digSum = 0;
        int factSum = 0;
        int temp=n;
        
        // find sum of digits
        while(temp)
        {
            digSum+=temp%10;
            temp = temp/10;
        }
        
        // find factors and their sum
        int i=2;
        temp = n;
        
        while(i<temp && n>1)
        {
            if( (n%i==0) && (isPrime(i)) )
            {
                n = n/i;
                factSum+=sumOfDigs(i);
            }
            else
                i++;
                
        }
        
        // cout<<digSum<<" "<<factSum<<endl;
        
        return digSum==factSum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends