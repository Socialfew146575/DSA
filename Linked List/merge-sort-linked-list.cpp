#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int d)
    {

        data = d;
        this->next = nullptr;
    }
};

void print(Node *head)
{
    cout << endl;
    cout << "[  ";
    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "X ]";

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

Node *merge(Node *first, Node *second)
{

    if (first == nullptr)
        return second;
    if (second == nullptr)
        return first;

    Node *ans = new Node(-1);
    Node *newHead = ans;

    Node *temp1 = first;
    Node *temp2 = second;
    while (temp1 != nullptr && temp2 != nullptr)
    {
        if (temp1->data < temp2->data)
        {

            insertAtTail(ans, newHead, temp1->data);
            temp1 = temp1->next;
        }
        else
        {
            insertAtTail(ans, newHead, temp2->data);
            temp2 = temp2->next;
        }
    }

    if (temp1 != nullptr)
    {
        newHead->next = temp1;
    }
    if (temp2 != nullptr)
    {
        newHead->next = temp2;
    }

    return ans->next;
}

Node *findMid(Node *head)
{
    Node *fast = head->next;
    Node *slow = head;

    while (fast != nullptr && fast->next != nullptr)
    {

        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node *mergeSort(Node *head)
{

    if (head == nullptr || head->next == nullptr)
        return head;

    Node *mid = findMid(head);

    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    Node *result = merge(left, right);

    return result;
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;
    insertAtTail(head, tail, 6);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 4);

    print(head);

    Node*ans=mergeSort(head);
    print(ans);
}