#include <bits/stdc++.h>
using namespace std;

class Dequeue
{

    int *arr;
    int size;
    int front;
    int rear;

public:
    Dequeue(int s)
    {
        size = s;
        arr = new int[s];
        front = rear = -1;
    }

    void pushFront(int d)
    {

        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {

            cout << "Queue is full" << endl;
            return;
        }
        else if (front == -1)
        {
            rear = front = 0;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
        }
        else
        {

            front--;
        }

        arr[front] = d;
    }

    void pushBack()
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {

            cout << "Queue is full" << endl;
            return;
        }
        else if (front == -1)
        {
            rear = front = 0;
        }
        else if (rear = size - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
    }

    void popFront()
    {
        if (front == -1)
        {

            cout << "Queue is empty" << endl;
            return;
        }
        if (front == rear)
        {

            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
            front++;
    }

    void popBack()
    {

        if (front == -1)
        {

            cout << "Queue is empty" << endl;
            return;
        }
        if (front == rear)
        {

            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
            rear--;
    }
};

int main()
{

    return 0;
}