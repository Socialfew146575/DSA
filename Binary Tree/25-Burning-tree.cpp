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

node *createMapping(node *root, int target, map<node *, node *> &nodeToParent)
{
    queue<node *> q;
    q.push(root);
    nodeToParent[root] = NULL;
    node *res = nullptr;

    while (!q.empty())
    {

        node *front = q.front();
        q.pop();
        if (front->data == target)
        {
            res = front;
        }

        if (front->left)
        {

            q.push(front->left);
            nodeToParent[front->left] = front;
        }
        if (front->right)
        {

            q.push(front->right);
            nodeToParent[front->right] = front;
        }
    }

    return res;
}

int burnTree(node *targetNode, map<node *, node *> nodeToParent)
{

    map<node *, bool> visited;
    queue<node *> q;
    visited[targetNode] = 1;
    q.push(targetNode);
    int ans = 0;
    while (!q.empty())
    {

        int n = q.size();
        bool flag = 0;

        for (int i = 0; i < n; i++)
        {
            node *front = q.front();
            q.pop();
            if (front->left && !visited[front->left])
            {

                flag = 1;
                visited[front->left] = 1;
                q.push(front->left);
            }
            if (front->right && !visited[front->right])
            {

                flag = 1;
                visited[front->right] = 1;
                q.push(front->right);
            }

            if (nodeToParent[front] && !visited[nodeToParent[front]])
            {
                flag = 1;
                visited[nodeToParent[front]] = 1;
                q.push(nodeToParent[front]);
            }
        }

        if (flag == 1)
        {
            ans++;
        }
    }
    return ans;
}

int minTime(node *root, int target)
{

    map<node *, node *> nodeToParent;
    node *targetNode = createMapping(root, target, nodeToParent);

    int ans = burnTree(targetNode, nodeToParent);
    return ans;
}

int main()
{
    node *root = nullptr;

    // 1 3 5 7 9 11 13 -1 -1 -1 -1 -1 -1
    buildFromLevelOrder(root);
    levelorderTraversal(root);
    cout << endl;
    cout << minTime(root, 8);
    return 0;
}