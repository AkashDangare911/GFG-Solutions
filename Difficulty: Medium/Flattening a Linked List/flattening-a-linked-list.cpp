/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    // Naive approach
    Node *flatten(Node *root) {
       vector<int> arr;
       Node* temp = root;
       
    //   traverse and push in array
       while(temp)
       {
           arr.push_back(temp->data);
           Node* down = temp->bottom;
           
           while(down)
           {
               arr.push_back(down->data);
               down=down->bottom;
           }
           temp=temp->next;
       }
       
    //   sort the array
       sort(arr.begin(),arr.end());
       
       Node* listHead = new Node(0);
       Node* listPtr = listHead;
       
    //   iterate and create new nodes for each data
    // and assign bottom pointer to cur node
       for(int i:arr)
       {
           Node* cur = new Node(i);
           listHead->bottom=cur;
           listHead=cur;
       }
       
       return listPtr->bottom;
    }
};