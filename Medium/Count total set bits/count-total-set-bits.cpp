//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    
    int nearestPow(int num)
    {
        int cnt=0;
        int i=1;
        
        while(i<=num)
        {
            i=i*2;
            cnt++;
        }
        
        return cnt-1;
    }
    
    int countSetBits(int n)
    {
        if(n==0)
            return 0;
            
        int p = nearestPow(n);
        int val = 1<<p;
        
        int ans = p*(val/2)+1+(n-val)+countSetBits(n-val);
        
        return ans;
    }
};



//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends