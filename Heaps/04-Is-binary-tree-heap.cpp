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

node *buildTree(node *root)
{

    cout << "Enter the data to enter the node:" << endl;
    int data;
    cin >> data;

    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
}

void buildFromLevelOrder(node *&root)
{

    {

        queue<node *> q;
        cout << "Enter data for root : ";
        int data;
        cin >> data;
        root = new node(data);
        q.push(root);

        while (!q.empty())
        {
            node *temp = q.front();
            q.pop();

            cout << "Enter left node for " << temp->data << endl;
            int leftdata;
            cin >> leftdata;

            if (leftdata != -1)
            {
                temp->left = new node(leftdata);
                q.push(temp->left);
            }

            cout << "Enter right node for " << temp->data << endl;
            int rightdata;
            cin >> rightdata;

            if (rightdata != -1)
            {
                temp->right = new node(rightdata);
                q.push(temp->right);
            }
        }
    }
}

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

int count(node *root)
{

    if (root == nullptr)
        return 0;

    int ans = 1 + count(root->left) + count(root->right);
    return ans;
}
// Is complete binary tree?
bool isCBT(node *root, int i, int nodeCount)
{

    if (root == nullptr)
        return true;

    if (i >= nodeCount)
        return false;

    bool left = isCBT(root->left, 2 * i + 1, nodeCount);
    bool right = isCBT(root->right, 2 * i + 2, nodeCount);

    return left && right;
}

bool isMaxOrder(node *root)
{

    if (root->left == nullptr && root->right == nullptr)
        return true;

    if (root->right == nullptr)
    {
        return (root->data > root->left->data);
    }
    else
    {

        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return (left && right && (root->data > root->left->data && root->data > root->right->data));
    }
}

bool isMaxHeap(node *root)
{

    int n = count(root);

    if (isCBT(root, 0, n) && isMaxOrder(root))
        return true;

    return false;
}
int main()
{
    node *root = nullptr;

    // 1 3 5 7 9 11 13 -1 -1 -1 -1 -1 -1 -1 -1
    // 1 10 -1 5 -1 -1 -1
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

    // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

    buildFromLevelOrder(root);
    levelorderTraversal(root);
    cout << endl;
    cout << isMaxHeap(root);
    return 0;
}