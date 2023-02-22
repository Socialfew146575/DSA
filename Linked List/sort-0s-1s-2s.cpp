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

        if(this->next!=nullptr){
            delete next;
            this->next=nullptr;
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

void sort1(Node *&head)
{

    if (head == nullptr || head->next == nullptr)
        return;

    int countZero = 0;
    int countOne = 0;
    int countTwo = 0;

    Node *temp = head;

    while (temp != nullptr)
    {
        if (temp->data == 0)
            countZero++;

        else if (temp->data == 1)
            countOne++;
        else
            countTwo++;

        temp = temp->next;
    }

    temp = head;
    while (temp != nullptr)
    {
        if (countZero-- > 0)
            temp->data = 0;
        else if (countOne-- > 0)
            temp->data = 1;
        else
            temp->data = 2;

        temp = temp->next;
    }
}

Node* sort2(Node *&head)
{

    if (head == nullptr || head->next == nullptr)
        return head;

    Node*zeroHead=new Node(-1);
    Node*zeroTail=zeroHead;
    Node*oneHead=new Node(-1);
    Node*oneTail=oneHead;
    Node*twoHead=new Node(-1);
    Node*twoTail=twoHead;

    Node*temp=head;

    while(temp!=nullptr){
        

        if(temp->data==0){
            zeroTail->next=temp;
            zeroTail=temp;
    
        }
        else if(temp->data==1){
            oneTail->next=temp;
            oneTail=temp;
        
        }
        else{
            twoTail->next=temp;
            twoTail=temp;
        
        }

        temp=temp->next;

    }
          
 
    if(oneHead->next!=nullptr){
        
        zeroTail->next=oneHead->next;
    }
    else{
        zeroTail->next=twoHead->next;
    }

    oneTail->next=twoHead->next;
    twoTail->next=nullptr;

    Node*newHead=zeroHead->next;


    return newHead;



}

int main()
{
    Node *head = nullptr;

    InsertAtPosition(head, 1, 1);
    InsertAtPosition(head, 2, 0);
    InsertAtPosition(head, 3, 2);
    InsertAtPosition(head, 4, 1);
    InsertAtPosition(head, 5, 2);
    InsertAtPosition(head, 6, 0);
    InsertAtPosition(head, 7, 0);
    InsertAtPosition(head, 8, 2);
    print(head);

    // sort1(head);
    // print(head);

    head=sort2(head);
   
    print(head);
    

    return 0;
}