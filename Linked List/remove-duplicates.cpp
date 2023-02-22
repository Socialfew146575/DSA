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

        delete next;
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

void removeDuplicateUnSorted(Node *&head)
{

    if (head == nullptr || head->next == nullptr)
        return;

    Node *curr = head;
    Node *prev = nullptr;
    // Node *fwd = nullptr;
    map<int,bool>mp;

    while (curr != nullptr)
    {   if(mp[curr->data]){
        prev->next=curr->next;
        curr->next=nullptr;
        delete curr;
        curr=prev->next;

    }
    else{
        mp[curr->data]=true;
        prev=curr;
        curr=curr->next;

    }


    }
}

void removeDuplicateUnsorted2(Node*&head){

    if(head==nullptr || head->next==nullptr) return;

    Node*curr=head;

    while (curr->next!=nullptr)
    {
        Node*temp=curr->next;
        Node*prev=curr;

        while (temp!=nullptr)
        {
            if(temp->data==curr->data){

                prev->next=temp->next;
                temp->next=nullptr;
                delete temp;
                temp=prev->next;


            }
            else{
                temp=temp->next;
                prev=prev->next;
            }
        }
        curr=curr->next;
        
        
    }
    



}

void removeDuplicateSorted(Node*&head){

        if (head == nullptr || head->next == nullptr)
        return;

    Node *curr = head->next;
    Node *prev = head;
    Node *fwd = nullptr;

    while (curr!=nullptr)
    {
        fwd=curr->next;

        if(curr->data==prev->data){
            prev->next=curr->next;
            curr->next=nullptr;
            delete curr;
            curr=fwd;

        }
        else{
            prev=prev->next;
            curr=fwd;
        }
        
    }
    

}



int main()
{
    Node *head = nullptr;
    // InsertAtPosition(head, 1, 10);
    // InsertAtPosition(head, 2, 10);
    // InsertAtPosition(head, 3, 20);
    // InsertAtPosition(head, 4, 30);
    // InsertAtPosition(head, 5, 30);
    // InsertAtPosition(head, 6, 30);
    // InsertAtPosition(head, 7, 40);
    // InsertAtPosition(head, 8, 40);
    // print(head);

    // removeDuplicateSorted(head);
    // print(head);

    InsertAtPosition(head, 1, 20);
    InsertAtPosition(head, 2, 10);
    InsertAtPosition(head, 3, 30);
    InsertAtPosition(head, 4, 40);
    InsertAtPosition(head, 5, 10);
    InsertAtPosition(head, 6, 30);
    InsertAtPosition(head, 7, 20);
    InsertAtPosition(head, 8, 30);
    print(head);

    // removeDuplicateUnSorted(head);
    // print(head);
    removeDuplicateUnsorted2(head);
    print(head);

    return 0;
}