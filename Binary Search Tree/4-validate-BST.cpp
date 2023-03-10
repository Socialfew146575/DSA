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

    if (root == nullptr)
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

void inOrder(Node *root, vector<int> &ans)
{

    if (root == nullptr)
        return;

    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right, ans);
}

bool checkSorted(vector<int> ans)
{

    for (int i = 1; i < ans.size(); i++)
    {
        if (ans[i] < ans[i - 1])
            return false;
    }

    return true;
}
bool isBST(Node *root, int min, int max)
{

    if (root == nullptr)
        return true;

    if (root->data > min && root->data <= max)
    {
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;
    }

    else
        return false;
}

bool validateBST(Node *root)
{

    return isBST(root, INT_MIN, INT_MAX);
}

int main()
{
    Node *root = NULL;

    cout << "Enter data to create BST" << endl;
    takeInput(root);
    levelOrderTravesal(root);
    cout << endl;
    vector<int> inorder;
    inOrder(root, inorder);
    if (checkSorted(inorder))
    {
        cout << "Binary Tree is a BST" << endl;
    }
    else
    {

        cout << "Not a BST" << endl;
    }
   if (validateBST(root))
    {
        cout << "Binary Tree is a BST" << endl;
    }
    else
    {

        cout << "Not a BST" << endl;
    }

    return 0;
}