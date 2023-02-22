#include <bits/stdc++.h>
using namespace std;

queue<int> rev(queue<int> q)
{
    queue<int> ans;
    stack<int> st;

    while (!q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        ans.push(st.top());
        st.pop();
    }

    return ans;
}

void rev2(queue<int>&q)
{
    if (q.empty())
        return;

    int ele = q.front();
    q.pop();
    rev2(q);
    q.push(ele);
}

int main()
{

    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);
    queue<int> ans = rev(q);

    // queue<int> sol=rev2(q);
    
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;

    while (!ans.empty())
    {
        cout << ans.front() << " ";
        ans.pop();
    }

    cout << endl;
      q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);

    rev2(q);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;

    return 0;
}