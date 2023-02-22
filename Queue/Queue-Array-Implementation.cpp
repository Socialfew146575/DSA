#include <bits/stdc++.h>
using namespace std;

class Queue
{

    int *arr;
    int qfront;
    int rear;
    int size;

public:
    Queue(int size)
    {

        this->size = size;
        this->qfront = 0;
        this->rear = 0;

        arr = new int[size];
    }

    void enqueue(int d)
    {

        if (rear == size)
        {
            cout << "Queue is full";
            return;
        }

        arr[rear] = d;
        rear++;
    }

    void dequeue()
    {

        if (qfront == rear)
        {
            cout << "Queue is empty";
            return;
        }
        else
        {
            qfront++;
            if (qfront == rear)
            {

                qfront = 0;
                rear = 0;
            }
        }
    }

    int front()
    {

        if (qfront == rear)
            return -1;

        else
        {
            return arr[qfront];
        }
    }

    bool isEmpty()
    {

        if (qfront == rear)
            return true;
        else
            return false;
    }

    void Display()
    {
        int i;
        if (qfront == rear)
        {
            printf("\nQueue is Empty\n");
            return;
        }

        // traverse qfront to rear and print elements
        for (i = qfront; i < rear; i++)
        {
            printf(" %d <-- ", arr[i]);
        }
        cout<<endl;
        return;
    }

    ~Queue() { delete[] arr; }
};

int main()
{
    
    // Create a queue of capacity 4
    Queue q(4);
 
    // print Queue elements
    q.Display();
 
    // inserting elements in the queue
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
 
    // print Queue elements
    q.Display();
 
    // insert element in the queue
    q.enqueue(60);
 
    // print Queue elements
    q.Display();
 
    q.dequeue();
    q.dequeue();
 
    printf("\n\nafter two node deletion\n\n");
 
    // print Queue elements
    q.Display();
 
    // print qfront of the queue
    printf("\nThe front of the queue is \n");
    cout<<q.front()<<endl;

    q.dequeue();
    q.dequeue();

    printf("\nIs the Queue empty or not?\n");
    cout<<q.isEmpty();

    return 0;
}