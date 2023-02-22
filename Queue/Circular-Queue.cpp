#include <bits/stdc++.h>
using namespace std;

class CircularQueue
{

    int *arr;
    int front;
    int rear;
    int size;

public:
    CircularQueue(int size)
    {

        this->size = size;
        rear = front = -1;
        arr = new int[size];
    }

    void enqueue(int d)
    {

        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {

            cout << "Queue is full" << endl;
            return;
        }

        else if (front == -1)
        {

            front = rear = 0;
            arr[rear] = d;
        }

        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = d;
        }

        else
        {
            rear++;
            arr[rear] = d;
        }
    }

    void dequeue()
    {

        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        else if (front == rear)
        {

            front = rear = -1;
        }

        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }

    void display()
    {

        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        else if (rear >= front)
        {

            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        else
        {

            for (int i = front; i < size; i++)
            {
                cout << arr[i] << " ";
            }

            for (int i = 0; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }

            cout << endl;
        }
    }
};

int main()
{   
    
    CircularQueue q(5);
 
    // Inserting elements in Circular Queue
    q.enqueue(14);
    q.enqueue(22);
    q.enqueue(13);
    q.enqueue(-6);
 
    // Display elements present in Circular Queue
    q.display();
 
    // Deleting elements from Circular Queue
    q.dequeue();
    q.dequeue();
  
 
    q.display();
 
    q.enqueue(9);
    q.enqueue(20);
    q.enqueue(5);
 
    q.display();
 
    q.enqueue(20);

    return 0;
}