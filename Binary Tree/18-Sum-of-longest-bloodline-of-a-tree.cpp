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

void solve(node *root, int &maxLen, int &maxSum, int len, int sum)
{

    if (root == nullptr)
    {
        if (len > maxLen)
        {
            maxSum = sum;
            maxLen = len;
        }
        else if (len == maxLen)
        {

            maxSum = max(sum, maxSum);
        }
        return;
    }

    sum += root->data;

    solve(root->left, maxLen, maxSum, len + 1, sum);
    solve(root->right, maxLen, maxSum, len + 1, sum);
}

int sum(node *root)
{

    int len = 0;
    int maxLen = 0;
    int sum = 0;
    int maxSum = INT_MIN;
    solve(root, maxLen, maxSum, len, sum);
    return maxSum;
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

    cout << "Sum of longest Bloodline of the three is : " << sum(root);

    return 0;
}