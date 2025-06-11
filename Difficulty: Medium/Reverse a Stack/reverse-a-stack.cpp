// User function Template for C++

class Solution {
  private:
    void putElementAtBottom(stack<int> &st, int element)
    {
        if(st.empty())
        {
            st.push(element);
            return;
        }
        
        int cur = st.top();
        st.pop();
        
        putElementAtBottom(st,element);
        st.push(cur);
    }
    
  public:
    void Reverse(stack<int> &st) {
        if(st.empty())
            return;
            
        int top = st.top();
        st.pop();
        
        Reverse(st);
        putElementAtBottom(st,top);
    }
};