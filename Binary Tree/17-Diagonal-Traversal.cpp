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

void solve(node *root, map<int, vector<int>> &diagonal, int d)
{

    if (root == nullptr)
        return;

    diagonal[d].push_back(root->data);

    solve(root->left, diagonal, d + 1);
    solve(root->right, diagonal, d);
}

vector<int> diagonalTraversal(node *root)
{

    map<int, vector<int>> diagonal;
    vector<int> ans;
    if (root == nullptr)
        return ans;

    solve(root, diagonal, 0);

    for (auto i : diagonal)
    {
        for (auto j : i.second)
        {
            ans.push_back(j);
        }
    }

    return ans;
}

vector<vector<int>> diagonalTraversal2(node *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
        return ans;

    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int s = q.size();
        vector<int> res;

        while (s--)
        {
            node *temp = q.front();
            q.pop();

            while (temp)
            {
                res.push_back(temp->data);
                if (temp->left)
                    q.push(temp->left);

                temp = temp->right;
            }
        }
        ans.push_back(res);
    }
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

    vector<int> ans = diagonalTraversal(root);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout<<endl;
    vector<vector<int>> res = diagonalTraversal2(root);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}