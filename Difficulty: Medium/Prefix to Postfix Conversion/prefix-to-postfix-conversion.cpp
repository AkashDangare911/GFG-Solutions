// User function Template for C++

class Solution {
  private:
    bool isOperand(char c)
    {
      return ((c>='a' && c<='z') || 
              (c>='A' && c<='Z') || 
              (c>='0' && c<='9'));
    }
    
  public:
    string preToPost(string s) {
        stack<string> st;
        
        for(int i=s.size()-1;i>=0;i--)
        {
            char c=s[i];
            
            if(isOperand(c)){
                st.push(string(1,c));
            }
            else
            {
                string s1=st.top();
                st.pop();
                string s2=st.top();
                st.pop();
                
                string ans = s1 + s2 + c;
                st.push(ans);
            }
        }
        
        return st.top();
    }
};