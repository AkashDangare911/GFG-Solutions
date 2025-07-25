// User function Template for C++

class Solution {
    bool isOperand(char c)
    {
      return ((c>='a' && c<='z') || 
              (c>='A' && c<='Z') || 
              (c>='0' && c<='9'));
    }
    
  public:
    string postToInfix(string s) {
        stack<string> st;
        
        for(int i=0;i<s.size();i++)
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
                
                string ans = "(" + s2 + c + s1 + ")";
                st.push(ans);
            }
        }
        
        return st.top();
    }
};