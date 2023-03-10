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


Node *inorderToBst(int s, int e, vector<int> &v)
{

    if (s > e)
        return nullptr;

    int mid = (s + e) / 2;

    Node *root = new Node(v[mid]);

    root->left = inorderToBst(s, mid - 1, v);
    root->right = inorderToBst(mid + 1, e, v);

    return root;
}

Node *bstFromInorder(Node *root,vector<int>in)
{
   

    return inorderToBst(0, in.size() - 1, in);
}

int main()
{
    Node *root = NULL;

    // cout << "Enter data to create BST" << endl;
    // takeInput(root);
    // levelOrderTravesal(root);
    // cout << endl;
    vector<int>v={10,11,12,13,14,15,16,17,18,19,20};
    root = bstFromInorder(root,v);
    levelOrderTravesal(root);

    return 0;
}