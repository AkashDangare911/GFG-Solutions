//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std;


// } Driver Code Ends
//User function template in C++


class Solution{
    public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]
    
    //Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> a1, int n, vector<int> a2, int m) 
    {
        map<int,int> mp;
        int cur=0;
        
        for(int i:a1)
            mp[i]++;
            
        for(int i=0;i<m;i++)
        {
            if(mp.count(a2[i]))
            {
                int cnt=mp[a2[i]];
                
                while(cnt)
                {
                    a1[cur]=a2[i];
                    cur++;
                    cnt--;
                }
                mp[a2[i]]=0;
            }
        }
        
        for(pair<int,int> p:mp)
        {
            if(p.second>0)
            {
                int cnt=p.second;
                
                while(cnt)
                {
                    a1[cur]=p.first;
                    cur++;
                    cnt--;
                }
                
                mp[p.first] = 0;
            }
        }
        
        return a1;
    } 
};


//{ Driver Code Starts.

int main(int argc, char *argv[]) 
{ 
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    
	    vector<int> a1(n);
	    vector<int> a2(m);
	    
	    for(int i = 0;i<n;i++){
	        cin >> a1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> a2[i];
	    }
	    
	    Solution ob;
	    a1 = ob.sortA1ByA2(a1, n, a2, m); 
	
	   
	    for (int i = 0; i < n; i++) 
		    cout<<a1[i]<<" ";
		
	    cout << endl;
	    
	    
	}
	return 0; 
} 

// } Driver Code Ends