#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // Destructor
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }

        cout << "Memory is free for node with data " << value << endl;
    }
};

void InsertAtHead(Node *&head, int d)
{

    // create a new node
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node *&tail, int d)
{

    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void InsertAtPosition(Node *&head, Node *&tail, int position, int d)
{
    // insert at start
    if (position == 1)
    {
        InsertAtHead(head, d);
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
        InsertAtTail(tail, d);
        return;
    }

    Node *ptr = new Node(d);
    ptr->next = temp->next;
    temp->next = ptr;
}

void deleteNode(Node *&head, Node *&tail, int position)
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

        if (curr->next == NULL)
        {
            tail = prev;
        }

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

int main()
{
    // created a new node
    Node *node1 = new Node(10);
    // cout << node1->data << endl;
    // cout << node1->next << endl;

    // head pointed to node
    Node *head = node1;

    // tail pointed to node
    Node *tail = node1;
    print(head);

    InsertAtHead(head, 12);
    print(head);

    InsertAtHead(head, 16);
    print(head);

    InsertAtTail(tail, 8);
    print(head);

    InsertAtPosition(head, tail, 2, 14);
    print(head);

    InsertAtPosition(head, tail, 1, 18);
    print(head);

    InsertAtPosition(head, tail, 7, 6);
    print(head);

    cout << head->data << " " << tail->data << endl;

    deleteNode(head, tail, 1);
    print(head);

    cout << head->data << " " << tail->data << endl;

    deleteNode(head, tail, 6);
    print(head);

    cout << head->data << " " << tail->data << endl;

    return 0;
}