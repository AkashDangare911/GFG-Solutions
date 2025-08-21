class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
       priority_queue<int,vector<int>, greater<int>> pq;
       int index=0;
       
    //   as each element is at-most 'k' places away from actual position,
    // we would eventually get correct element in first 'k' elements
       for(int i:arr)
       {
           pq.push(i);
           
           if(pq.size()>k)
           {
               arr[index]=pq.top();
               index++;
               pq.pop();
           }
       }
       
       while(!pq.empty())
       {
           arr[index]=pq.top();
           index++;
           pq.pop();
       }
    }
};