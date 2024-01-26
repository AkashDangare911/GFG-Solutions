//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        priority_queue<pair<double,int>> pq;
        double ans=0;
        
        for(int i=0;i<n;i++)
            pq.push({(1.0*arr[i].value)/(1.0*arr[i].weight),arr[i].weight});
        
        
        while(!pq.empty())
        {
            if(pq.top().second < w)  
            {
                ans+=pq.top().first*pq.top().second;
                w-=pq.top().second;
                // cout<<"added -> "<<pq.top().first*pq.top().second<<endl;
            }
            else
            {
                ans+=pq.top().first*w;
                // cout<<"added-> "<<pq.top().first*w<<endl;
                break;
            }
           
           pq.pop();
        }
            
        return ans;
    }
    // 4 5
    // 6 2 8 6 10 9 8 3
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends