// User function Template for C++

class Solution {
  private:
    bool isOperand(char c)
    {
      if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
        return true;
        
      return false;
    }
    
  public:
    string preToInfix(string s) {
        stack<string> st;
        
        for(int i=s.size()-1;i>=0;i--)
        {
            char c=s[i];
            
            if(isOperand(c)){
                string ans="";
                ans.push_back(c);
                st.push(ans);
            }
            else
            {
                string s1=st.top();
                st.pop();
                string s2=st.top();
                st.pop();
                
                string ans = "(" + s1 + c + s2 + ")";
                st.push(ans);
            }
        }
        
        string ans=st.top();
        return ans;
    }
};