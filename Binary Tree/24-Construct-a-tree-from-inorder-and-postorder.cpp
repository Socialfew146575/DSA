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

void preOrder(node *root)
{

    if (root == nullptr)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
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

node *solve(vector<int> inorder, vector<int> postorder, int &index, int inorderStart, int inorderEnd, int n, map<int, int> nodeToIndex)
{

    if (index < 0 || inorderStart > inorderEnd)
    {

        return NULL;
    }
    int ele = postorder[index--];
    node *root = new node(ele);
    int pos = nodeToIndex[ele];

    root->right = solve(inorder, postorder, index, pos + 1, inorderEnd, n, nodeToIndex);
    root->left = solve(inorder, postorder, index, inorderStart, pos - 1, n, nodeToIndex);

    return root;
}

node *buildtree(vector<int> inorder, vector<int> postorder, int n)
{
    map<int, int> nodeToIndex;
    for (int i = 0; i < n; i++)
    {
        nodeToIndex[inorder[i]] = i;
    }
    int index = n - 1;
    node *root = solve(inorder, postorder, index, 0, n - 1, n, nodeToIndex);
    return root;
}
int main()
{
    vector<int> inorder = {4, 8, 2, 5, 1, 6, 3, 7};
    vector<int> postorder = {8, 4, 5, 2, 6, 7, 3, 1};

    node *root = buildtree(inorder, postorder, 8);

    levelorderTraversal(root);
    cout << endl;
    preOrder(root);

    return 0;
}