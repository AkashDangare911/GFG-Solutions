//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
private:
    string sub(string big,string small)
    {
        int n1=big.size(),n2=small.size();
        int i=n1-1,j=n2-1;
        int carry=0;
        string ans="";
        
        // 100
        //  12
        
        while(i>=0 || j>=0 || carry)
        {
            int a=0,b=0;
            
            if(i>=0)
            {
                a = big[i]-'0';
                i--;
            }
            
            if(j>=0)
            {
                b=small[j]-'0';
                j--;
            }
            
            int cur = a+carry-b;
            if(cur<0)
            {
                cur+=10;
                carry=-1;
            }
            else
                carry=0;
                
            // if(cur!=0)
            ans.push_back(cur%10 +'0');
        }
        
        i=0;
        int sz=ans.size();
        reverse(ans.begin(),ans.end());
        
        while(i<sz && ans[i]=='0')
            i++;
        
        // cout<<"ans is -> "<<ans<<endl;
        if(i>=sz)
            return "0";
            
        // cout<<"ans is -> "<<ans<<endl;
        return ans.substr(i);
    }
    
public:
    Node* subLinkedList(Node* head1, Node* head2) 
    {
        // cout<<"for head1\n";
        while(head1!=NULL && head1->data==0)
        {
            // cout<<head1->data<<" ";
            head1=head1->next;
        }
        // cout<<endl;
            
        // cout<<"for head2\n";
        while(head2!=NULL && head2->data==0)
        {
            // cout<<head2->data<<" ";
            head2=head2->next;
        }
        // cout<<endl;
        
        // if one num is zero
        if(head1==NULL && head2==NULL)
        {
            Node * n = new Node(0);
            return n;
        }
        
        if(head1==nullptr)
            return head2;
        if(head2==nullptr)
            return head1;
            
        string a="";
        while(head1)
        {
            a+=('0'+ head1->data);
            head1=head1->next;
        }
        
        string b="";
        while(head2)
        {
            b+=('0'+head2->data);
            head2=head2->next;
        }
        
        // cout<<a<<endl<<b<<endl;
        string ans="";
        
        if(a.size()>b.size())
            ans = sub(a,b);
        // cout<<"ans is-> "<<ans<<endl;
        else if(b.size()>a.size())
            ans = sub(b,a);
        else
        {
            int n=a.size();
            int i=0;
            
            while(i<n && a[i]==b[i])
                i++;
            
            // both nos are same
            if(i>=n)
                return new Node(0);
            
            if(a[i]>b[i])
            {
                ans = sub(a,b);
            }
            else
                ans = sub(b,a);
        }
        
        Node *res = new Node(0);
        Node *ret = res;
    
        for(char c:ans)
        {
            Node *cur = new Node(c-'0');
            res->next=cur;
            res=res->next;
        }
        
        return ret->next;
        // return NULL;
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends