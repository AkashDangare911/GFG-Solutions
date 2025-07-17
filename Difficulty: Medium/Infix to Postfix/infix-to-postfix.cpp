class Solution {
  private:
      int precedence(char c)
      {
        if(c=='^') return 3;
        if (c=='*' || c=='/') return 2;
        if(c=='+' || c=='-')  return 1;
        if(c=='(') return 0;
      }
      
      bool isOperand(char c)
      {
          if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
            return true;
            
          return false;
      }
  
  public:
    string infixToPostfix(string& s) {
        string ans="";
        stack<char> st;
        
        for(char c:s)
        {
            if(isOperand(c))
                ans.push_back(c);
            else if(c=='(')
                st.push(c);
            else if(c==')')
            {
                while(!st.empty() && st.top()!='(')
                {
                    char ele=st.top();
                    st.pop();
                    ans.push_back(ele);
                }
                st.pop();
            }
            else
            {
                while(!st.empty() && precedence(c) <= precedence(st.top()))
                {
                    char ele=st.top();
                    st.pop();
                    ans.push_back(ele);
                }
                st.push(c);
            }
        }
        
         while(!st.empty())
        {
            char ele=st.top();
            st.pop();
            ans.push_back(ele);
        }
        
        return ans;
    }
};
