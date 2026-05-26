// User function Template for C++

class Solution {
  private:
    void exploreIsland(int i, int j, int baseI, int baseJ, vector<pair<int,int>> &cur, 
        vector<vector<int>>& vis, vector<vector<int>>& grid)
    {
        // check if out of boud
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return;
        
        // check if is land and ignore already visited land
        if(grid[i][j]==0 || vis[i][j])
            return;
        
        vis[i][j]=1;    // mark as visited
        
        
        // build the island dimentions
        pair<int,int> curDist = {baseI-i, baseJ-j};
        cur.push_back(curDist);
        
        // explore all 4 directions
        exploreIsland(i,j+1,baseI,baseJ,cur,vis,grid);
        exploreIsland(i,j-1,baseI,baseJ,cur,vis,grid);
        exploreIsland(i+1,j,baseI,baseJ,cur,vis,grid);
        exploreIsland(i-1,j,baseI,baseJ,cur,vis,grid);
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        set<vector<pair<int,int>>> st;
        vector<vector<int>> vis(n, vector<int> (m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // start with top-left point of unvisited land
                if(grid[i][j] && !vis[i][j])
                {
                    vector<pair<int,int>> cur;
                    exploreIsland(i,j,i,j,cur,vis,grid);
                    st.insert(cur);
                }
            }
        }
        
        // set will store only unique islands
        return st.size();
    }
};
