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

int totalNumberOfNodes(Node *root)
{
   
    if (root == NULL)
        return 0;

    int l = totalNumberOfNodes(root->left);
    int r = totalNumberOfNodes(root->right);

    return (1 + l + r);
}

int solve(Node *root, int &i, int k)
{
    if (root == nullptr)
    {
        return -1;
    }

    int left = solve(root->left, i, k);
    if (left != -1)
    {
        return left;
    }
    i++;

    if (i == k)
    {
        return root->data;
    }

    return solve(root->right, i, k);
}

int kthSmallest(Node *root, int k)
{
    int i = 0;
    int ans = solve(root, i, k);
    return ans;
}

int kthLargest(Node *root, int k)
{

    int i = 0;
    k = totalNumberOfNodes(root) - k + 1;

    int ans = solve(root, i, k);
    return ans;
}

void morrisTraversal(Node *root, int k)
{
    int i = 0;
    if (root == nullptr)
        return;

    Node *current = root;
    Node *pre = nullptr;

    while (current)
    {
        if (current->left == nullptr)
        {
            // cout << current->data << " ";
            i++;
            if (i == k)
            {
                cout << current->data << endl;
                
            }
            current = current->right;
        }

        else
        {

            pre = current->left;

            while (pre->right && pre->right != current)
            {
                pre = pre->right;
            }

            if (pre->right == nullptr)
            {

                pre->right = current;
                current = current->left;
            }
            else
            {

                i++;
                if (i == k)
                {
                    cout << current->data << endl;
                  
                }
                pre->right = nullptr;
                current = current->right;
            }
        }
    }
}

int main()
{
    Node *root = NULL;

    cout << "Enter data to create BST" << endl;
    takeInput(root);
    levelOrderTravesal(root);
    cout << endl;
    int n=totalNumberOfNodes(root);
   
    cout << kthSmallest(root, 3);
    cout << endl;
    morrisTraversal(root, 3);
    cout << endl;
    cout << kthLargest(root, 3);
    cout << endl;
    morrisTraversal(root, totalNumberOfNodes(root) - 3 + 1);

    return 0;
}