#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node *random;

    Node(int d)
    {

        data = d;
        this->next = nullptr;
        this->random = nullptr;
    }
};

void printNext(Node *head)
{
    cout << endl;
    cout << "[ ";
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << " ]";
}
void printRandom(Node *head)
{
    int k = 5;
    cout << "\t";
    cout << "[ ";
    while (k-- > 0)
    {
        cout << head->data << " ";
        head = head->random;
    }

    cout << " ]";
    cout << endl
         << endl;
}

void insertAtTail(Node *&head, Node *&tail, int d)
{

    Node *node = new Node(d);
    if (head == nullptr)
    {
        head = node;
        tail = head;
    }
    else
    {
        tail->next = node;
        tail = node;
    }
}

int search(Node *head, Node *target)
{

    Node *temp = head;
    int k = 0;
    while (temp != target)
    {
        k++;
        temp = temp->next;
    }

    return k;
}

Node *clone1(Node *head)
{
    Node *curr1 = head;

    Node *newHead = nullptr;
    Node *newTail = nullptr;

    while (curr1 != nullptr)
    {
        insertAtTail(newHead, newTail, curr1->data);
        curr1 = curr1->next;
    }
    curr1 = head;
    Node *curr2 = newHead;

    while (curr1 != nullptr)
    {
        int k = search(head, curr1->random);
        Node *node = newHead;
        while (k-- > 0)
        {
            node = node->next;
        }
        curr2->random = node;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return newHead;
}

Node *clone2(Node *head)
{

    Node *curr1 = head;

    Node *newHead = nullptr;
    Node *newTail = nullptr;

    while (curr1 != nullptr)
    {
        insertAtTail(newHead, newTail, curr1->data);
        curr1 = curr1->next;
    }

    unordered_map<Node *, Node *> mp;

    curr1 = head;
    Node *curr2 = newHead;
    while (curr1 != nullptr)
    {
        mp[curr1] = curr2;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    curr1 = head;
    curr2 = newHead;

    while (curr2 != nullptr)
    {
        curr2->random = mp[curr1->random];
        curr2 = curr2->next;
        curr1 = curr1->next;
    }

    return newHead;
}

Node *clone3(Node *head)
{

    Node *curr1 = head;

    Node *newHead = nullptr;
    Node *newTail = nullptr;

    while (curr1 != nullptr)
    {
        insertAtTail(newHead, newTail, curr1->data);
        curr1 = curr1->next;
    }

    curr1 = head;
    Node *curr2 = newHead;
    Node *nxt = nullptr;

    while (curr2 != nullptr)
    {
        nxt = curr1->next;
        curr1->next = curr2;
        curr1 = nxt;

        nxt = curr2->next;
        curr2->next = curr1;
        curr2 = nxt;
    }

    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->next != NULL)
        {

            temp->next->random = temp->random ? temp->random->next : temp->random;
        }

        temp = temp->next->next;
    }

    curr1 = head;
    curr2 = newHead;

    while (curr2 != nullptr && curr1 != nullptr)
    {
        curr1->next = curr2->next;
        curr1 = curr1->next;

        if (curr1 != nullptr)
            curr2->next = curr1->next;
        curr2 = curr2->next;
    }

    return newHead;
}

int main()
{

    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);

    Node *head = node1;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = nullptr;
    node1->random = node3;
    node2->random = node1;
    node3->random = node5;
    node4->random = node3;
    node5->random = node2;

    printNext(head);
    printRandom(head);

    Node *ans1 = clone1(head);
    printNext(ans1);
    printRandom(ans1);
    Node *ans2 = clone2(head);
    printNext(ans2);
    printRandom(ans2);

    Node *ans3 = clone3(head);
    printNext(ans3);
    printRandom(ans3);
    return 0;
}