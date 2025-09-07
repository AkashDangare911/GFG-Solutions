/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  private:
    Node* mergeTwoLists(Node* list1, Node* list2) {
        Node* cur = new Node(0);
        Node* curPtr = cur;

        // untill one of the list exhausts
        while(list1 && list2)
        {
            if(list1->data < list2->data)
            {
                cur->next=list1;
                list1=list1->next;
            }
            else
            {
                cur->next=list2;
                list2=list2->next;
            }
            cur=cur->next;
        }

        // if any list exhausts, attach cur to other list 
        // as further nodes are already in sorted order
        if(list1)
            cur->next=list1;
        else
            cur->next=list2;

        return curPtr->next;
    }
  public:
    Node* mergeKLists(vector<Node*>& arr) {
       Node* nextNode = NULL;
       Node* cur = arr[0];
       
       for(int i=1;i<arr.size();i++)
       {
            nextNode = mergeTwoLists(arr[i],cur);
            cur=nextNode;
       }
       
       return cur;
    }
};