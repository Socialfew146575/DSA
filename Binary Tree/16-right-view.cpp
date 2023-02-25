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

vector<int> rightView(node *root)
{

    vector<int> ans;

    if (root == nullptr)
        return ans;

    map<int, int> leftNode;
    queue<pair<node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<node *, int> temp = q.front();
        q.pop();
        node *node = temp.first;
        int lvl = temp.second;

        leftNode[lvl] = node->data;

        if (node->left)
        {

            q.push(make_pair(node->left, lvl + 1));
        }
        if (node->right)
        {

            q.push(make_pair(node->right, lvl + 1));
        }
    }

    for (auto i : leftNode)
    {

        ans.push_back(i.second);
    }
    return ans;
}

void solve(node *root, vector<int> &ans, int lvl)
{

    if (root == nullptr)
        return;

    if (lvl == ans.size())
    {
        ans.push_back(root->data);
    }

     solve(root->right, ans, lvl + 1);
    solve(root->left, ans, lvl + 1);
}

vector<int> rightViewRecursive(node *root)
{

    vector<int> ans;
    solve(root, ans, 0);

    return ans;
}

int main()
{
    node *root = nullptr;

    // 1 3 5 7 9 11 13 -1 -1 -1 -1 -1 -1 -1 -1
    // 1 10 -1 5 -1 -1 -1
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    // 1 2 5 3 4 -1 6 -1 -1 -1 7 -1 8 -1 -1 -1 9 -1 -1
    // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

    buildFromLevelOrder(root);
    levelorderTraversal(root);
    cout << endl;

    vector<int> ans = rightView(root);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<int> res = rightViewRecursive(root);

    for (auto i : res)
    {
        cout << i << " ";
    }

    return 0;
}