#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int d)
    {

        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {

        if (this->next != nullptr)
        {
            delete next;
            this->next = nullptr;
        }
    }
};

void InsertAtPosition(Node *&head, int position, int d)
{
    if (head == nullptr)
    {
        Node *temp = new Node(d);
        temp->next = nullptr;
        head = temp;
        return;
    }

    // insert at start
    if (position == 1)
    {
        Node *temp = new Node(d);
        temp->next = head;
        head = temp;

        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt++ < position - 1)
    {
        temp = temp->next;
    }

    // insert at last position
    if (temp->next == NULL)
    {
        Node *node = new Node(d);
        temp->next = node;
        node->next = nullptr;
        return;
    }

    Node *ptr = new Node(d);
    ptr->next = temp->next;
    temp->next = ptr;
}

void deleteNode(Node *&head, int position)
{

    // deleting first or start node
    if (position == 1)
    {

        Node *temp = head;
        head = head->next;

        // freeing memory of start node
        temp->next = NULL;
        delete temp;
    }
    // deleting last or middle node
    else
    {
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt++ < position)
        {

            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        curr->next = NULL;
        delete curr;
    }
}

void print(Node *&head)
{
    Node *ptr = head;

    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }

    cout << endl;
}

void solve(vector<int> v)
{

    int i = 0;
    int j = v.size() - 1;

    while (i <= j)
    {
        if (v[i++] != v[j--])
        {
            cout << "Not Palindrome " << endl;
            return;
        }
    }

    cout << "Palindrome" << endl;
}

void palindrome(Node *head)
{

    vector<int> v;

    Node *temp = head;
    while (temp != nullptr)
    {
        v.push_back(temp->data);
        temp = temp->next;
    }

    solve(v);
}

Node *getMid(Node *head)
{

    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node *reverse(Node *head)
{

    Node *prev = nullptr;
    Node *curr = head;
    Node *fwd = nullptr;
    while (curr != nullptr)
    {
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }

    return prev;
}

// Without Extra space
void palindrome2(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        cout << "NOT PALINDROME" << endl;
        return;
    }

    Node *middle = getMid(head);

    Node *temp = middle->next;
    middle->next = reverse(temp);

    Node *head1 = head;
    Node *head2 = middle->next;

    while (head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            cout << "NOT PALINDROME" << endl;
            return;
        }

        head2 = head2->next;
        head1 = head1->next;
    }

    temp = middle->next;
    middle->next = reverse(temp);
    cout << "PALINDROME" << endl;
}

int main()
{
    Node *head = nullptr;

    InsertAtPosition(head, 1, 1);
    InsertAtPosition(head, 2, 3);
    InsertAtPosition(head, 3, 2);
    InsertAtPosition(head, 4, 5);
    InsertAtPosition(head, 5, 3);
    InsertAtPosition(head, 6, 1);

    print(head);

    palindrome2(head);
    print(head);
    return 0;
}