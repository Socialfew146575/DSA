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
        next = nullptr;
    }
};

class Queue
{

    Node *front;
    Node *rear;

public:
    Queue()
    {

        front = rear = nullptr;
    }

    void enqueue(int d)
    {
        // cout << "*" << endl;
        Node *node = new Node(d);

        if (rear == nullptr)
        {

            front = rear = node;
            return;
        }

        rear->next = node;
        rear = node;
    }

    void dequeue()
    {
        // cout << "*" << endl;
        if (front == nullptr)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        Node *temp = front;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
    }

    int queuefront()
    {

        if (front == nullptr)
        {
            return -1;
        }

        return front->data;
    }

    void display()
    {
        // cout << "*" << endl;
        if (front == nullptr)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        Node *temp = front;

        while (temp != rear->next)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();

    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}