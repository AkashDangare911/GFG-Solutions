// User function Template for C++

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head, int key) {
        Node* temp=*head;
        Node* pr=temp->prev;
        
        // delete starting keys
        while(temp && temp->data == key)
        {
            Node* t = temp;
            temp=temp->next;
            delete t;
        }
        
        // re-initialize
        *head=temp;
        pr=nullptr;
        if(temp){
            temp->prev=nullptr;
        }
        
        while(temp)
        {
            if(temp->data == key)
            {
                Node *nxt = temp->next;
                Node* cur=temp;
                pr->next=nxt;
                if(nxt)
                    nxt->prev=pr;
                delete cur;
                temp=nxt;
            }
            else
            {
                pr=temp;
                temp=temp->next;
            }
        }
    }
};