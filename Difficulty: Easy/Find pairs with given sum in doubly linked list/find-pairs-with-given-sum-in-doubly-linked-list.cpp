// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        Node* st=head;
        Node* en=st;
        vector<pair<int, int>> ans;
        
        // move to last
        while(en->next)
            en=en->next;
        
        while(st != en)
        {
            int sum = st->data + en->data;
            if(sum < target)
            {
                st=st->next;
            }
            else if(sum>target)
            {
                en=en->prev;
            }
            else
            {
                ans.push_back({st->data,en->data});
                st=st->next;
            }
        }
        
        return ans;
    }
};