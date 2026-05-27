class Solution {
  private:
    bool dfs(int ind, vector<int> &vis, vector<int> &pathVis, vector<int> adj[])
    {
        // node has occured in the path once-again,
        // this confirms, we found a cycle
        if(pathVis[ind])
            return true;
        
        // don't explore the pre-visited nodes
        if(vis[ind])
            return false;
            
        // mark visited
        vis[ind]=1;
        pathVis[ind]=1;
        
        // traverse adjacent nodes
        for(int i:adj[ind])
        {
            if(dfs(i,vis,pathVis,adj))
                return true;
        }
        
        // remove from visited node from path, but keep it as marked as visited
        pathVis[ind]=0;
        
        // none of the paths found cycle
        return false;
    }
    
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int> adj[V+1];
        vector<int> vis(V,0), pathVis(V,0);
        
        // formulate adjacency list
        for(int i=0;i<edges.size();i++)
            adj[edges[i][0]].push_back(edges[i][1]);
        
        // for dis-connected components
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,vis,pathVis,adj))
                    return true;
            }
        }
        
        return false;
    }
};