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

bool search(Node *root, int target)
{

    if (root == nullptr)
    {
        return false;
    }
    if (root->data == target)
    {

        return true;
    }

    if (target > root->data)
    {
        return search(root->right, target);
    }
    else
    {
        return search(root->left, target);
    }
}

bool searchIterative(Node *root, int target)
{

    Node *temp = root;

    while (temp != NULL)
    {
        if (temp->data == target)
        {
            return true;
        }
        else if (temp->data > target)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    return false;
}

int main()
{
    Node *root = NULL;

    cout << "Enter data to create BST" << endl;
    takeInput(root);
    levelOrderTravesal(root);
    cout << endl;
    if (search(root, 7))
    {
        cout << 7 << " is present in the BST" << endl;
    }
    else
    {
        cout << 7 << " is not present in the BST" << endl;
    }
    if (searchIterative(root, 7))
    {
        cout << 7 << " is present in the BST" << endl;
    }
    else
    {
        cout << 7 << " is not present in the BST" << endl;
    }

    return 0;
}