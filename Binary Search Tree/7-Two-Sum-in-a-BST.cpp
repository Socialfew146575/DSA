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

void inorderTraversal(Node *root, vector<int> &v)
{

    if (root == nullptr)
    {
        return;
    }

    inorderTraversal(root->left, v);
    v.push_back(root->data);
    inorderTraversal(root->right, v);
}

bool twoSumBST(Node *root, int target)
{

    vector<int> inorder;
    inorderTraversal(root, inorder);

    int i = 0, j = inorder.size() - 1;

    while (i < j)
    {
        if (inorder[i] + inorder[j] == target)
        {    cout << inorder[i] << " " << inorder[j] << endl;
        return true;}
        else if (inorder[i] + inorder[j] > target)
        {
            j--;
        }
        else
        {
            i++;
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
    if (twoSumBST(root, 9))
    {
        cout << "9 is possible by adding two nodes data..." << endl;
    }
    else
    {
        cout << "9 is not possible by adding two nodes data..." << endl;
    }
    return 0;
}