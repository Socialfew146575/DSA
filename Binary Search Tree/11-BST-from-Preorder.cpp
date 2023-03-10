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
Node *solve(vector<int> &preorder, int min, int max, int &i)
{

    if (i >= preorder.size())
        return nullptr;

    if (preorder[i] < min && preorder[i] > max)
        return nullptr;

    Node *root = new Node(preorder[i++]);
    root->left = solve(preorder, min, root->data, i);
    root->right = solve(preorder, root->data, max, i);
    return root;
}
Node *preorderToBst(vector<int> &preorder)
{

    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solve(preorder, mini, maxi, i);
}

int main()
{
    // Node *root = NULL;

    // cout << "Enter data to create BST" << endl;
    // takeInput(root);
    // levelOrderTravesal(root);
    // cout << endl;
    vector<int> v = {20, 10, 5, 15, 13, 35, 30, 42};
    Node *root = preorderToBst(v);
    levelOrderTravesal(root);

    return 0;
}