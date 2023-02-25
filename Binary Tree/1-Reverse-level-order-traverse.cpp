#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

node *buildTree(node *root)
{

    cout << "Enter the data to enter the node:" << endl;
    int data;
    cin >> data;

    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
}

void reverseorderTraversal(node *root)
{   
  

    queue<node *> q;
    stack<node *> s;
    q.push(root);
    
    while (!q.empty())
    {
        node *temp = q.front();

        q.pop();
        s.push(temp);

      
        
            if (temp->right)
            {
                q.push(temp->right);
            }
            if (temp->left)
            {
                q.push(temp->left);
            }

            
    }

    while (!s.empty())
    {   
        node *temp = s.top();

        s.pop();
       
   
            cout << temp->data << " ";
    }
}

int main()
{
    node *root = nullptr;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);
    reverseorderTraversal(root);
    return 0;
}