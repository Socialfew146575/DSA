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

Node *minValue(Node *root)
{

    if (root->left == nullptr)
        return root;

    return minValue(root->left);
}

void findPreSuc(Node *root, int key, Node *&pre, Node *&suc)
{

    if (root == nullptr)
        return;

    if (root->data == key)
    {

        if (root->left)
        {

            Node *tmp = root->left;

            while (tmp->right)
            {
                tmp = tmp->right;
            }
            pre = tmp;
        }
        if (root->right)
        {

            Node *tmp = root->right;

            while (tmp->left)
            {
                tmp = tmp->left;
            }
            suc = tmp;
        }
    }
    if (root->data > key)
    {

        suc = root;
        findPreSuc(root->left, key, pre, suc);
    }
    else
    {
        pre = root;
        findPreSuc(root->right, key, pre, suc);
    }
}

int main()
{
    Node *root = NULL;

    cout << "Enter data to create BST" << endl;
    takeInput(root);
    levelOrderTravesal(root);
    cout << endl;
    Node *min = minValue(root);
    cout << "Min Value in the BST is " << min->data;
    cout << endl;
    Node *pre = nullptr;
    Node *suc = nullptr;

    findPreSuc(root, 65, pre, suc);
    cout << "Inorder Predecessor of 65 is " << pre->data << endl;
    cout << "Inorder Successor of 65 is " << suc->data << endl;

    return 0;
}