#include <bits/stdc++.h>
using namespace std;

class Queue
{

    stack<int> s1, s2;

public:
    void push(int x)
    {

        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop()
    {

        if (s1.empty())
        {
            cout << "Queue is empty" << endl;
        }

        s1.pop();
    }

    int front()
    {

        if (s1.empty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        return s1.top();
    }
};

int main()
{

    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.front() << '\n';
    q.pop();
    cout << q.front() << '\n';
    q.pop();

    cout << q.front() << '\n';

    return 0;
}