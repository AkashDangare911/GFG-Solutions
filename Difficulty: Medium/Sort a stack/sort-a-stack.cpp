/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */
void sortedInsert(stack<int> &st, int element)
{
    if(st.empty())
    {
        st.push(element);
        return;
    }
    
    if(st.top()<=element)
    {
        st.push(element);
        return;
    }
    
    int cur = st.top();
    st.pop();
    
    sortedInsert(st,element);
    st.push(cur);
}
    
void SortedStack ::sort() {
    if(s.empty())
        return;
    
    int top = s.top();
    s.pop();
    sort();
    sortedInsert(s,top);
}