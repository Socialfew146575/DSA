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

// External space
Node *merge1(Node *&first, Node *&second)
{
    if (first == nullptr)
        return second;
    if (second == nullptr)
        return first;

    Node *dummy = new Node(-1);
    Node *tail = dummy;
    Node *temp1 = first;
    Node *temp2 = second;

    while (temp1 != nullptr && temp2 != nullptr)
    {

        if (temp1->data > temp2->data)
        {

            tail->next = temp2;
            tail = temp2;
            temp2 = temp2->next;
        }
        else
        {
            tail->next = temp1;
            tail = temp1;
            temp1 = temp1->next;
        }
    }

    if (temp1 != NULL)
    {
        tail->next = temp1;
    }
    if (temp2 != NULL)
    {
        tail->next = temp2;
    }

    return dummy->next;
}

Node *solve(Node *first, Node *second)
{

    if (first->next == nullptr)
    {
        first->next = second;
        return first;
    }

    Node *curr1 = first;
    Node *next1 = first->next;
    Node *curr2 = second;

    while (curr2 != NULL && next1 != NULL)
    {

        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            Node *next2 = curr2->next;
            curr1->next = curr2;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {

            curr1 = curr1->next;
            next1 = next1->next;

            if (next1 == NULL)
            {
                curr1->next = curr2;
            }
        }
    }

    return first;
}

// Inplace
Node *merge2(Node *first, Node *second)
{
    if (first == nullptr)
        return second;
    if (second == nullptr)
        return first;

    if (first->data < second->data)
    {

        return solve(first, second);
    }
    else
    {

        return solve(second, first);
    }
}

int main()
{
    Node *head1 = nullptr;

    InsertAtPosition(head1, 1, 1);
    // InsertAtPosition(head1, 2, 3);
    // InsertAtPosition(head1, 3, 5);

    Node *head2 = nullptr;

    InsertAtPosition(head2, 1, 2);
    // InsertAtPosition(head2, 2, 4);
    // InsertAtPosition(head2, 3, 5);

    print(head1);
    print(head2);

    // Node *head3 = merge1(head1, head2);
    // print(head3);
    Node *head3 = merge2(head1, head2);
    print(head3);

    return 0;
}