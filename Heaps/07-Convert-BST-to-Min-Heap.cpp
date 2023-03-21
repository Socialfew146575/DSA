#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *right;
    Node *left;

    Node(int d)
    {

        this->data = d;
        this->right = NULL;
        this->left = NULL;
    }
};

Node *insertIntoBST(Node *root, int data)
{

    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }
}

void takeInput(Node *&root)
{

    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >>
            data;
    }
}

void levelOrderTravesal(Node *root)
{

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {

            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
// Linerar Solution Space : O(m+n) , Time : O(m+n)

void inorderTraversal(Node *root, vector<int> &in)
{

    if (root == NULL)
        return;

    inorderTraversal(root->left, in);
    in.push_back(root->data);
    inorderTraversal(root->right, in);
}

void solve(Node *&root, int &indx, vector<int> &in)
{

    if (root == NULL)
        return;

    root->data = in[indx++];
    solve(root->left, indx, in);
    solve(root->right, indx, in);
}

Node *bstToMinHeap(Node *root)
{

    vector<int> in;
    inorderTraversal(root, in);
    int indx = 0;

    solve(root, indx, in);
    return root;
}

int main()
{
    Node *root = NULL;

    cout << "Enter data to create BST" << endl;
    takeInput(root);
    levelOrderTravesal(root);
    cout << endl;

    root = bstToMinHeap(root);
    levelOrderTravesal(root);
    cout << endl;

    return 0;
}