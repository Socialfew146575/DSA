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

void insertNode(Node *&tail, int element, int d)
{

    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }

        Node *temp = new Node(d);

        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node *&tail, int element)
{

    if (tail == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != element)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        // 1 Node link list
        if (curr == prev)
        {
            tail = NULL;
        }

        else if (tail == curr)
        {
            tail = prev;
        }

        curr->next = NULL;

        delete curr;
    }
}

void print(Node *tail)
{
    Node *temp = tail;

    if (tail == NULL)
    {
        cout << " List is empty " << endl;
        return;
    }
    do
    {
        cout << tail->data << " ";
        tail = tail->next;

    } while (tail != temp);

    cout << endl;
}

bool isCircular(Node *head)
{
    if (head == nullptr)
        return true;

    auto temp = head->next;

    while (temp != nullptr && temp != head)
    {
        temp = temp->next;
    }

    if (temp == head)
        return true;

    return false;
}

bool detectLoop(Node *head)
{

    if (head == nullptr)
        return false;

    map<Node *, bool> visited;
    auto temp = head;

    while (temp != nullptr)
    {
        if (visited[temp] == true)
        {

            cout << "Present on element"
                 << " " << temp->data << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}


bool floydDetectLoop(Node*head){

    if(head==nullptr)return false;

    auto slow=head;
    auto fast=head->next;

    while(fast!=slow){

        if(fast==nullptr || fast->next==nullptr) return false;

        slow=slow->next;
        fast=fast->next->next;
    }

    return true;

}

int main()
{
    Node *tail = NULL;
    insertNode(tail, 10, 10);
    print(tail);

    insertNode(tail, 10, 20);
    print(tail);

    insertNode(tail, 20, 30);
    print(tail);

    cout << isCircular(tail) << endl;
    
    cout<<detectLoop(tail)<<endl;
    cout<<floydDetectLoop(tail)<<endl;

    deleteNode(tail, 30);
    print(tail);
    deleteNode(tail, 20);
    print(tail);
    deleteNode(tail, 10);
    print(tail);

    return 0;
}