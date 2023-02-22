#include <bits/stdc++.h>
using namespace std;
// By making push operation costly
class Stack1
{

    queue<int> q1, q2;

public:
    void push(int x)
    {

        q2.push(x);

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    void pop()
    {

        q1.pop();
    }
    int top()
    {
        if (q1.empty())
            return -1;
        return q1.front();
    }

    int size() { return q1.size(); }
};

// using one queue
class Stack2
{

    queue<int> q;

public:
    void push(int x)
    {
        int n = q.size();
        q.push(x);

       

        for (int i = 0; i < n; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    void pop()
    {

        q.pop();
    }
    int top()
    {
        if (q.empty())
            return -1;
        return q.front();
    }

    int size() { return q.size(); }
};

int main()
{
    Stack1 s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "current size: " << s.size() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    cout << "current size: " << s.size() << endl;
    Stack2 s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);

    cout << "current size: " << s1.size() << endl;
    cout << s1.top() << endl;
    s1.pop();
    cout << s1.top() << endl;
    s1.pop();
    cout << s1.top() << endl;

    cout << "current size: " << s1.size() << endl;
   

    return 0;
}