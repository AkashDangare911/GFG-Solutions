class Solution {
  private:
    vector<int> rInd = {1,0,0,-1};
    vector<int> cInd = {0,-1,1,0};
    vector<char> dir = {'D','L','R','U'};
        
    void findPath(int i, int j, string path, vector<vector<int>>& maze, vector<string> &ans)
    {
        // rat reached the destination
        if(i==maze.size()-1 && j==maze.size()-1)
        {
            ans.push_back(path);
            return;
        }
        
        // out of bound
        if(i<0 || j<0 || i>=maze.size() || j>=maze.size())
            return;
        
        // no further path or already visited
        if(maze[i][j]==0 || maze[i][j]==2)
            return;
        
        // mark as visited
        maze[i][j]=2;
        
        for(int ind=0;ind<4;ind++)
        {
            path.push_back(dir[ind]);
            findPath(i+rInd[ind],j+cInd[ind],path,maze,ans);
            path.pop_back();
        }
        
        // make it unvisited (it can't be '0' as we return earlier for '0')
        maze[i][j]=1;
    }
    
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        string path="";
        
        findPath(0,0,path,maze,ans);
        
        return ans;
    }
};