class Solution {
    stack<pair<int,int>> st;
  public:
    Solution() {
        
    }

    // Add an element to the top of Stack
    void push(int x) {
        if(st.empty())
        {
            st.push({x,x});
            return;
        }
        
        int mn = min(x,st.top().second);
        st.push({x,mn});
    }

    // Remove the top element from the Stack
        
    void pop() {
        if(!st.empty())
            st.pop();
    }

        
    // Returns top element of the Stack
    int peek() {
        if(!st.empty())
            return st.top().first;
        return -1;
    }
        

    // Finds minimum element of Stack
    int getMin() {
        if(!st.empty())
            return st.top().second;
        return -1;
    }
};