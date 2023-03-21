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

class compare
{

public:
    bool
    operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

Node *mergeKSortedLinkedList(vector<Node *> &kList)
{

    priority_queue<Node *, vector<Node *>, compare> minHeap;

    for (int i = 0; i < kList.size(); i++)
    {
        minHeap.push(kList[i]);
    }
    Node *head = nullptr;
    Node *tail = head;
    while (minHeap.size() > 0)
    {
        Node *top = minHeap.top();
        minHeap.pop();

        if (top->next != nullptr)
        {
            minHeap.push(top->next);
        }
        if (head == nullptr)
        {
            head = top;
            tail = top;
        }
        else
        {
            tail->next = top;
            tail = top;
        }
    }
    return head;
}

int main()
{
    Node *head1 = nullptr;

    InsertAtPosition(head1, 1, 1);
    InsertAtPosition(head1, 2, 3);
    InsertAtPosition(head1, 3, 5);

    Node *head2 = nullptr;

    InsertAtPosition(head2, 1, 2);
    InsertAtPosition(head2, 2, 4);
    InsertAtPosition(head2, 3, 5);
    Node *head3 = nullptr;

    InsertAtPosition(head3, 1, 6);
    InsertAtPosition(head3, 2, 11);
    InsertAtPosition(head3, 3, 9);

    Node *head4 = nullptr;

    InsertAtPosition(head4, 1, 7);
    InsertAtPosition(head4, 2, 13);
    InsertAtPosition(head4, 3, 14);

    print(head1);
    print(head2);
    print(head3);
    print(head4);

    vector<Node *> kList = {head1, head2, head3, head4};

    Node *head = mergeKSortedLinkedList(kList);
    print(head);

    return 0;
}