#include <bits/stdc++.h>
using namespace std;

void display(queue<int> q)
{

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void solve(queue<int> &q, int k)
{

    stack<int> st;

    for (int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    for (int i = 0; i < q.size() - k; i++)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }
}

int main()
{

    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    display(q);

    solve(q,3);

    display(q);
    return 0;
}