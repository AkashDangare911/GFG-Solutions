class Solution {
  private:
    bool dfs(int ind, int prev, vector<int> &vis, vector<int> adj[])
    {
        // no cycle found this way
        if(ind>=vis.size())
            return false;
        
        // reached pre-visited node --> cycle detected
        if(vis[ind]==1)
            return true;
            
        // mark visited
        vis[ind]=1;
        
        // try other ways and check if we find any pre-visited node
        bool ans = false;
        for(int i:adj[ind])
        {
            if(i != prev)
                ans = ans || dfs(i,ind,vis,adj);
        }
        
        return ans;
    }
    
  public:
    // USING DFS
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        vector<int> vis(V,0);   // visited array
        
        // form adjacency list
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        // for dis-connected components
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,-1,vis,adj))
                    return true;
            }
        }
        
        return false;
    }
};