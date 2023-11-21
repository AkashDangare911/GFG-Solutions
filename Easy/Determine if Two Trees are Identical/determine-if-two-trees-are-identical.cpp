//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};


// } Driver Code Ends
/* A binary tree node


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/


   
class Solution
{
    private:
    bool checkIfSame(queue<Node*> t1,queue<Node*> t2)
    {
        int s1 = t1.size();
        int s2 = t2.size();
        
        if(s1!=s2)
            return false;
            
        for(int i=0;i<s1;i++)
        {
            Node *temp1 = t1.front();
            Node *temp2 = t2.front();
            t1.pop();
            t2.pop();
            
            if(temp1->data != temp2->data)
                return false;
                
            t1.push(temp1);
            t2.push(temp2);
        }
        
        return true;
    }
    
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        queue<Node*> t1,t2;
        t1.push(r1);
        t2.push(r2);
        
        while(!t1.empty() || !t2.empty())
        {
            if(checkIfSame(t1,t2) == false)
                return false;
            
            int s1 = t1.size();
            int s2 = t2.size();
            
            for(int i=0;i<s1;i++)
            {
                Node *n = t1.front();
                t1.pop();
                
                if(n->left)
                    t1.push(n->left);
                
                if(n->right)
                    t1.push(n->right);
            }
            
            
            for(int i=0;i<s2;i++)
            {
                Node *n = t2.front();
                t2.pop();
                
                if(n->left)
                    t2.push(n->left);
                
                if(n->right)
                    t2.push(n->right);
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string str, str1;
        getline(cin, str);
        Node *rootA = buildTree(str);
        getline(cin, str1);
        Node *rootB = buildTree(str1);
        Solution ob;
        if (ob.isIdentical(rootA, rootB)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
// } Driver Code Ends