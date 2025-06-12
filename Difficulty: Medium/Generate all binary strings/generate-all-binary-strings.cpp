// User function Template for C++

class Solution {
  private:
    void generateStrings(int i, string temp, int n, vector<string> &ans)
    {
        if(i==n)
        {
            ans.push_back(temp);
            return;
        }
        
        generateStrings(i+1,temp+'0',n,ans);
        
        // no 2 consecutive '1's allowed
        if(!(temp.back()=='1'))
            generateStrings(i+1,temp+'1',n,ans);
    }
  public:
    vector<string> generateBinaryStrings(int num) {
        vector<string> ans;
        
        generateStrings(1,"0",num,ans);
        generateStrings(1,"1",num,ans);
        
        return ans;
    }
};