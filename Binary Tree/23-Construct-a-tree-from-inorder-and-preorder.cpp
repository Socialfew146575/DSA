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

void levelorderTraversal(node *root)
{

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {

            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {

            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

void postOrder(node *root)
{

    if (root == nullptr)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int findPosition(int ele, vector<int> inorder, int n)
{

    for (int i = 0; i < n; i++)
    {
        if (ele == inorder[i])
        {
            return i;
        }
    }

    return -1;
}

node *solve(vector<int> inorder, vector<int> preorder, int &index, int inorderStart, int inorderEnd, int n, map<int, int> nodeToIndex)
{

    if (index >= n || inorderStart > inorderEnd)
    {
        return NULL;
    }

    int ele = preorder[index++];
    node *root = new node(ele);

    // int position = findPosition(ele, inorder, n);
    int position = nodeToIndex[ele];

    root->left = solve(inorder, preorder, index, inorderStart, position - 1, n, nodeToIndex);
    root->right = solve(inorder, preorder, index, position + 1, inorderEnd, n, nodeToIndex);

    return root;
}

node *buildtree(vector<int> inorder, vector<int> preorder, int n)
{
    map<int, int> nodeToIndex;

    for (int i = 0; i < n; i++)
    {
        nodeToIndex[inorder[i]] = i;
    }

    int index = 0;
    node *root = solve(inorder, preorder, index, 0, n - 1, n, nodeToIndex);

    return root;
}

int main()
{
    vector<int> inorder = {3, 1, 4, 0, 5, 2};
    vector<int> preorder = {0, 1, 3, 4, 2, 5};

    node *root = buildtree(inorder, preorder, 6);

    levelorderTraversal(root);
    cout << endl;
    postOrder(root);

    return 0;
}