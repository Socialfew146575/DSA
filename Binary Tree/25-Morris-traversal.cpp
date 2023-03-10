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

void inorder(node *root)
{

    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node *root)
{

    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root)
{

    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void morrisTraversalForInorder(node *root)
{

    if (root == nullptr)
        return;

    node *current = root;
    node *pre = nullptr;

    while (current)
    {
        if (current->left == nullptr)
        {

            cout << current->data << " ";
            current = current->right;
        }
        else
        {

            pre = current->left;
            while (pre->right != nullptr && pre->right != current)
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

                cout << current->data << " ";
                pre->right = nullptr;
                current = current->right;
            }
        }
    }
}

void morrisTraversalForPreorder(node *root)
{

    if (root == nullptr)
        return;

    node *current = root;
    node *pre = nullptr;
    while (current)
    {
        if (current->left == nullptr)
        {

            cout << current->data << " ";
            current = current->right;
        }

        else
        {

            pre = current->left;
            while (pre->right && pre->right != current)
            {
                pre = pre->right;
            }

            if (pre->right == current)
            {
                pre->right = nullptr;
                current = current->right;
            }
            else
            {
                cout << current->data << " ";
                pre->right = current;
                current = current->left;
            }
        }
    }
}

void morrisTraversalForPostorder(node *root)
{
    vector<int> ans;
    if (root == nullptr)
        return;

    node *current = root;
    node *pre = nullptr;

    while (current)
    {
        if (current->right == nullptr)
        {
            ans.push_back(current->data);
            current = current->left;
        }

        else
        {

            pre = current->right;
            while (pre->left && pre->left != current)
            {
                pre = pre->left;
            }

            if (pre->left == current)
            {

                pre->left = nullptr;
                current = current->left;
            }
            else
            {
                ans.push_back(current->data);
                pre->left = current;
                current = current->right;
            }
        }
    }

    reverse(ans.begin(), ans.end());
    for (auto i : ans)
    {
        cout << i << " ";
    }
}

int main()
{
    node *root = nullptr;

    // 1 3 5 7 9 11 13 -1 -1 -1 -1 -1 -1
    buildFromLevelOrder(root);
    levelorderTraversal(root);
    cout << endl;
    inorder(root);
    cout << endl;

    morrisTraversalForInorder(root);
    cout << endl;
    preorder(root);
    cout << endl;

    morrisTraversalForPreorder(root);
    cout << endl;
    postorder(root);
    cout << endl;

    morrisTraversalForPostorder(root);
    return 0;
}