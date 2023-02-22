#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node *prev;

    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node(){

        int value=this->data;

        if(this->next!=NULL && this->prev!=NULL){
            delete next;
            delete prev;

            this->next=NULL;
            this->prev=NULL;
        }
     cout << "Memory is free for node with data " << value << endl;
    }
};

void InsertAtHead(Node *&head, int d)
{

    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void InsertAtTail(Node *&head, int d)
{
    Node *temp = new Node(d);

    if(head==NULL){
        head=temp;
    }
    else{
           Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = temp;
    temp->prev = ptr;
    }
}

void InsertAtPosition(Node *&head, int position, int d)
{

    if (position == 1)
    {
        InsertAtHead(head, d);
        return;
    }

    Node *temp = new Node(d);
    Node *ptr = head;
    int cnt = 1;
    while (cnt++ < position - 1)
    {
        ptr = ptr->next;
    }

    if (ptr->next == NULL)
    {
        InsertAtTail(head, d);
        return;
    }

    temp->next = ptr->next;
    ptr->next->prev = temp;
    ptr->next = temp;
    temp->prev = ptr;
}
int getLength(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}

void deleteNode(Node *&head, int position)
{

    if (position == 1)
    {

        Node *temp = head;
        temp->next->prev = NULL;
        head = head->next;

        temp->next = NULL;
        delete temp;
    }
    else
    {

        Node *temp = head;
        int cnt = 1;
        while (cnt++ < position)
        {
            temp = temp->next;
        }

        if (temp->next == NULL)
        {
            temp->prev->next = NULL;
            temp->prev = NULL;
            temp->next = NULL;

        }
        else
        {

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            temp->next = NULL;
            temp->prev = NULL;
        }
        delete temp;
    }
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;

    print(head);
    cout << getLength(head) << endl;

    InsertAtHead(head, 12);
    print(head);
    InsertAtHead(head, 14);
    print(head);
    InsertAtHead(head, 18);
    print(head);
    InsertAtHead(head, 20);
    print(head);

    InsertAtTail(head, 8);
    print(head);

    InsertAtPosition(head, 3, 16);
    print(head);
    InsertAtPosition(head, 1, 22);
    print(head);

    InsertAtPosition(head, getLength(head) + 1, 6);
    print(head);

    deleteNode(head, 1);
    print(head);
    deleteNode(head, 3);
    print(head);

    deleteNode(head, getLength(head));
    print(head);

    return 0;
}