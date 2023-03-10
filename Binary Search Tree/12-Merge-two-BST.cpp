#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *right;
    Node *left;

    Node(int d)
    {

        this->data = d;
        this->right = NULL;
        this->left = NULL;
    }
};

Node *insertIntoBST(Node *root, int data)
{

    if (root == nullptr)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }
}

void takeInput(Node *&root)
{

    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >>
            data;
    }
}

void levelOrderTravesal(Node *root)
{

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {

            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
// Linerar Solution Space : O(m+n) , Time : O(m+n)

void inorderTraversal(Node *root, vector<int> &in)
{

    if (root == nullptr)
        return;

    inorderTraversal(root->left, in);
    in.push_back(root->data);
    inorderTraversal(root->right, in);
}

vector<int> mergeArray(vector<int> in1, vector<int> in2)
{

    int i = 0, j = 0;
    vector<int> ans;
    while (i < in1.size() && j < in2.size())
    {
        if (in1[i] < in2[j])
        {
            ans.push_back(in1[i++]);
        }
        else
        {
            ans.push_back(in2[j++]);
        }
    }

    while (i < in1.size())
    {
        ans.push_back(in1[i++]);
    }
    while (j < in2.size())
    {
        ans.push_back(in2[j++]);
    }

    return ans;
}
Node *inorderToBst(int s, int e, vector<int> &in)
{

    if (s > e)
        return nullptr;

    int mid = (s + e) / 2;
    Node *root = new Node(in[mid]);
    root->left = inorderToBst(s, mid - 1, in);
    root->right = inorderToBst(mid + 1, e, in);
    return root;
}
Node *merge2Bst(Node *root1, Node *root2)
{

    vector<int> in1;
    vector<int> in2;

    inorderTraversal(root1, in1);
    inorderTraversal(root2, in2);

    vector<int> in = mergeArray(in1, in2);

    return inorderToBst(0, in.size() - 1, in);
}

// Optimized Space(h1+h2)

// Convert BST into a sorted Linked List
void bstToSortedDLL(Node *root, Node *&head)
{

    if (root == nullptr)
        return;

    bstToSortedDLL(root->right, head);

    root->right = head;

    if (head != nullptr)
        head->left = root;

    head = root;
    bstToSortedDLL(root->left, head);
}

// Merge 2 Linked List

Node *merge2LL(Node *first, Node *second)
{

    if (first == nullptr)
        return second;
    if (second == nullptr)
        return first;

    Node *head = nullptr;
    Node *tail = nullptr;

    while (first != nullptr && second != nullptr)
    {

        if (first->data < second->data)
        {
            if (head == nullptr)
            {

                head = first;
                tail = first;
                first = first->right;
            }
            else
            {

                tail->right = first;
                first->left = tail;
                tail = first;
                first = first->right;
            }
        }
        else
        {
            if (head == nullptr)
            {

                head = second;
                tail = second;
                second = second->right;
            }
            else
            {

                tail->right = second;
                second->left = tail;
                tail = second;
                second = second->right;
            }
        }
    }

    while (first!=nullptr)
    {

        tail->right = first;
        first->left = tail;
        tail = first;
        first = first->right;
    }
    
    while (second!=nullptr)
    {
        tail->right = second;
        second->left = tail;
        tail = second;
        second = second->right;
    }
    
return head;
}

    // Sorted Linked List to BST
int countNodes(Node*head){

    int cnt=0;
    while (head!=nullptr)
    {
        head=head->right;
        cnt++;
    }
    return cnt;
    


}
Node*sortedLLToBst(Node*&head,int n){

    if(n<=0 || head==nullptr ){
        return nullptr;
    }

    Node*left=sortedLLToBst(head,n/2);
    Node*root=head;
    root->left=left;
    head=head->right;
    root->right=sortedLLToBst(head,n-n/2-1);
    return root;

}

Node* merge2BST(Node*root1,Node*root2){

    Node*head1=nullptr;
    bstToSortedDLL(root1,head1);
    head1->left=nullptr;

    Node*head2=nullptr;
    bstToSortedDLL(root2,head2);
    head2->left=nullptr;



    Node*head=merge2LL(head1,head2);

    return sortedLLToBst(head,countNodes(head));




}

int main()
{
    Node *root1 = NULL;

    cout << "Enter data to create BST" << endl;
    takeInput(root1);
    levelOrderTravesal(root1);
    cout << endl;
    Node *root2 = NULL;

    cout << "Enter data to create BST" << endl;
    takeInput(root2);
    levelOrderTravesal(root2);
    cout << endl;

    Node *root3 = merge2Bst(root1, root2);
    levelOrderTravesal(root3);
    
    Node*root4=merge2BST(root1,root2);
    levelOrderTravesal(root4);

    return 0;
}