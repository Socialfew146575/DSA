#include <bits/stdc++.h>
using namespace std;

int main()
{

    // Creating a queue
    queue<int> q;

    q.push(11);
    q.push(15);
    q.push(13);
    int n = q.size();
    cout << "Size of queue is : " << n << endl;

    cout << q.front() << " " << q.back() << endl;

    for (int i = 0; i < n; i++)
    {

        cout << q.front() << " ";
        q.pop();
    }

    q.empty() ? cout << "\nQueue is empty\n" : cout << "Queue is not empty ";

    return 0;
}