// C++ Program to flatten a given Binary Tree into linked
// list by using Morris Traversal concept
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
};

// utility that allocates a new Node with the given key
Node *newNode(int key)
{
    Node *node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return (node);
}

void flatten(Node *root)
{

    if (root == nullptr)
        return;

    Node *current = root;
    Node *pre = nullptr;

    while (current)
    {
        if (current->left)
        {

            pre = current->left;
            while (pre->right)
            {
                pre = pre->right;
            }

            pre->right = current->right;
            current->right = current->left;
            current->left = nullptr;
        }
        current = current->right;
    }
}
void flattenRecursive(struct Node *root)
{
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
    {
        return;
    }

    if (root->left)
    {

        flattenRecursive(root->left);

        Node *temp = root->right;
        root->right = root->left;
        root->left = nullptr;

        Node *ptr = root->right;
        while (ptr->right != nullptr)
        {
            ptr = ptr->right;
        }

        ptr->right = temp;
    }
    flattenRecursive(root->right);
}

// To find the inorder traversal
void inorder(struct Node *root)
{
    // base condition
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

/* Driver program to test above functions*/
int main()
{
    /* 1
        / \
    2	 5
    / \	 \
    3 4	 6 */
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->right = newNode(6);
    // flatten(root);
    flattenRecursive(root);
    cout << "The Inorder traversal after flattening binary tree ";
    inorder(root);
    return 0;
}
