//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        int ans=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        for(int i=0;i<n;i++)
            pq.push({price[i],i+1});
            
        
        while(!pq.empty())
        {
            int kimmat = pq.top().first;
            int amount = pq.top().second;
            
            if(kimmat*amount <= k)
            {
                k-=kimmat*amount;
                ans+=amount;
            }
            else
            {
                int num = k/kimmat;
                
                k-=(num*kimmat);
                ans+=num;
                break;
            }
            
            pq.pop();
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends