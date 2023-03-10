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

void inorderTraversal(Node *root, vector<Node *> &v)
{

    if (root == nullptr)
    {
        return;
    }

    inorderTraversal(root->left, v);
    v.push_back(root);
    inorderTraversal(root->right, v);
}

Node *flatten(Node *root)
{

    if (root == nullptr)
        return nullptr;

    vector<Node *> in;
    inorderTraversal(root, in);

    Node *temp = in[0];

    for (int i = 0; i < in.size() - 1; i++)
    {
        temp->left = nullptr;
        temp->right = in[i + 1];
        temp = temp->right;
    }

    temp->left = nullptr;
    temp->right = nullptr;

    return in[0];
}

void listTraversal(Node *root)
{

    if (root == nullptr)
        return;

    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }
}

int main()
{
    Node *root = NULL;

    cout << "Enter data to create BST" << endl;
    takeInput(root);
    levelOrderTravesal(root);
    cout << endl;
    root = flatten(root);
    listTraversal(root);

    return 0;
}