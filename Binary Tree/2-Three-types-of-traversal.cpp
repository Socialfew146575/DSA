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

void inorderTraversal(node *root)
{

    if (root == NULL)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void postorderTraversal(node *root)
{

    if (root == nullptr)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}
void preorderTraversal(node *root)
{

    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderIterative(node *root)
{
    stack<node *> s;
    node *curr = root;

    while (curr != NULL || s.empty() == false)
    {
        /* Reach the left most Node of the
           curr Node */
        while (curr != NULL)
        {
            /* place pointer to a tree node on
               the stack before traversing
              the node's left subtree */
            s.push(curr);
            curr = curr->left;
        }

        /* Current must be NULL at this point */
        curr = s.top();
        s.pop();

        cout << curr->data << " ";

        /* we have visited the node and its
           left subtree.  Now, it's right
           subtree's turn */
        curr = curr->right;

    } /* end of while */
}

void preorderIterative(node *root)
{

    stack<node *> s;
    s.push(root);

    while (!s.empty())
    {
        node *temp = s.top();
        s.pop();
        cout << temp->data << " ";

        if (temp->right)
        {
            s.push(temp->right);
        }
        if (temp->left)
        {
            s.push(temp->left);
        }
    }
}

void postorderIterative(node *root)
{

    
    stack<node *> s1,s2;

    s1.push(root);
    node *curr;

    while (!s1.empty())
    {
        /* code */curr=s1.top();
        s1.pop();
        s2.push(curr);

        if(curr->left) s1.push(curr->left);
        if(curr->right) s1.push(curr->right);
    }

    while (!s2.empty())
    {
        curr=s2.top();
        s2.pop();
        cout<<curr->data<<" ";
    }
    

}

int main()
{
    node *root = nullptr;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    cout << "Inorder Traversal\n";
    inorderTraversal(root);
    cout << endl;
    inorderIterative(root);
    cout << endl;
    cout << "Inorder Traversal\n";
    preorderTraversal(root);
    cout << endl;
    preorderIterative(root);
    cout << endl;
    cout << "Inorder Traversal\n";
    postorderTraversal(root);
    cout << endl;
    postorderIterative(root);
    return 0;
}