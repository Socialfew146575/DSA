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

Node *reverse(Node *&head)
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

Node *sum(Node *first, Node *second)
{

    if (first == nullptr)
        return second;
    if (second == nullptr)
        return first;

    first = reverse(first);
    second = reverse(second);
    // print(first);
    // print(second);

    Node *node = new Node(-1);
    Node *ptr = node;

    Node *curr1 = first;
    Node *curr2 = second;
    int carry = 0;
    while (curr1 != nullptr || curr2 != nullptr || carry != 0)
    {
        int val1 = 0;
        if (curr1 != NULL)
        {
            val1 = curr1->data;
        }

        int val2 = 0;
        if (curr2 != NULL)
        {
            val2 = curr2->data;
        }

        int sum = carry + val1 + val2;
        int rem = (sum) % 10;
        Node *n = new Node(rem);
        carry = (sum) / 10;
        ptr->next = n;
        ptr = ptr->next;

        if (curr1 != NULL)
            curr1 = curr1->next;

        if (curr2 != NULL)
            curr2 = curr2->next;
    }
    //   while (curr1 != nullptr && curr2 != nullptr)
    //     {

    //         int rem = (curr1->data + curr2->data + carry) % 10;
    //         Node *n = new Node(rem);
    //         carry = (curr1->data + curr2->data + carry) / 10;
    //         ptr->next = n;
    //         ptr = ptr->next;
    //         curr1 = curr1->next;
    //         curr2 = curr2->next;
    //     }

    //     while (curr1 != nullptr)
    //     {

    //         int rem = (curr1->data + carry) % 10;
    //         Node *n = new Node(rem);
    //         ptr->next = n;
    //         ptr = ptr->next;
    //         carry = (curr1->data + carry) / 10;
    //         curr1 = curr1->next;
    //     }
    //     while (curr2 != nullptr)
    //     {

    //         int rem = (curr2->data + carry) % 10;
    //         Node *n = new Node(rem);
    //         ptr->next = n;
    //         ptr = ptr->next;
    //         carry = (curr2->data + carry) / 10;
    //         curr2 = curr2->next;
    //     }
    //     if (carry == 1)
    //     {
    //         Node *n = new Node(1);
    //         ptr->next = n;
    //         ptr = ptr->next;
    //     }
    Node *newHead = node->next;
    newHead = reverse(newHead);

    return newHead;
}

int main()
{
    Node *head1 = nullptr;

    InsertAtPosition(head1, 1, 4);
    InsertAtPosition(head1, 2, 5);
    

    Node *head2 = nullptr;
    InsertAtPosition(head2, 1, 3);
    InsertAtPosition(head2, 2, 4);
    InsertAtPosition(head2, 3, 5);
   
    cout<<"\t ";
    print(head1);
    cout<<"\t+";
    print(head2);
    cout<<"    ---------------"<<endl;
    cout<<"\t ";
    Node *head3 = sum(head1, head2);
    print(head3);
    return 0;
}