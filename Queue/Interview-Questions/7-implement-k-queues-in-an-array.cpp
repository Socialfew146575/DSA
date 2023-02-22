#include <bits/stdc++.h>
using namespace std;

class kQueues
{

    int *arr;
    int *rear;
    int *front;
    int *next;
    int n, k;
    int free;

public:
    kQueues(int k1, int n1)
    {

        n = n1;
        k = k1;
        arr = new int[n];
        next = new int[n];
        rear = new int[k];
        front = new int[k];

        free = 0;

        for (int i = 0; i < k; i++)
        {
            rear[i] = -1;
            front[i] = -1;
        }
        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }

        next[n - 1] = -1;
    }

    bool isFull()
    {

        return free == -1;
    }
    bool isEmpty(int qn) { return (front[qn] == -1); }
    void enqueue(int x, int m)
    {
       
        if (isFull())
        {
            cout << "Queue overflow" << endl;
            return;
        }

        int index = free;
        free = next[index];

        if (front[m ] == -1)
        {
            front[m] = index;
        }
        else
        {

            next[rear[m]] = index;
        }
        next[index] = -1;
        rear[m] = index;
        arr[index] = x;
    }

    int dequeue(int m)
    {
        
        if (isEmpty(m))
        {
            cout << "\nQueue Underflow\n";
            return INT_MAX;
        }

        int index = front[m];
        front[m] = next[index];

        next[index] = free;
        free = index;
        return arr[index];
    }
};

int main()
{
    // Let us create 3 queue in an array of size 10
    int k = 3, n = 10;
    kQueues ks(k, n);

    // Let us put some items in queue number 2
    ks.enqueue(15, 2);
    ks.enqueue(45, 2);

    // Let us put some items in queue number 1
    ks.enqueue(17, 1);
    ks.enqueue(49, 1);
    ks.enqueue(39, 1);

    // Let us put some items in queue number 0
    ks.enqueue(11, 0);
    ks.enqueue(9, 0);
    ks.enqueue(7, 0);

    cout << "Dequeued element from queue 2 is " << ks.dequeue(2) << endl;
    cout << "Dequeued element from queue 1 is " << ks.dequeue(1) << endl;
    cout << "Dequeued element from queue 0 is " << ks.dequeue(0) << endl;

    return 0;
}