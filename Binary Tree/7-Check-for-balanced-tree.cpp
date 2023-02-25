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
int height(node *root)
{

    if (root == nullptr)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return max(left, right) + 1;
}

bool isBalanced(node *root)
{
    if (root == nullptr)
        return true;

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool condn = abs(height(root->left) - height(root->right)) <= 1;

    return left && right && condn;
}

pair<bool, int> fastBalanced(node *root)
{

    if (root == nullptr)
    {

        return {true, 0};
    }

    pair<bool, int> left = fastBalanced(root->left);
    pair<bool, int> right = fastBalanced(root->right);

    bool op1 = left.first;
    bool op2 = right.second;
    bool op3 = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;

    ans.first = op1 && op2 && op3;
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int main()
{
    node *root = nullptr;

    // 1 3 5 7 9 11 13 -1 -1 -1 -1 -1 -1 -1 -1
    // 1 10 -1 5 -1 -1 -1

    buildFromLevelOrder(root);
    levelorderTraversal(root);

    cout << "\n Is Tree balanced or Not?? " << isBalanced(root) << endl;
    cout << "\n Is Tree balanced or Not?? " << fastBalanced(root).first << endl;

    return 0;
}