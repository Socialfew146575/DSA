#include <bits/stdc++.h>
using namespace std;

queue<int> interleave(queue<int> q)
{

    queue<int> ans;
    queue<int> p;
    int n = q.size();
    for (int i = 0; i < n / 2; i++)
    {
        p.push(q.front());
        q.pop();
    }

    int m = p.size();

    for (int i = 0; i < m; i++)
    {
        ans.push(p.front());
        ans.push(q.front());
        q.pop();
        p.pop();
    }

    return ans;
}
queue<int> interleave2(queue<int> q)
{

    queue<int> ans;
    stack<int>st;
    
    int n=q.size();
    for (int i = 0; i < n/2; i++)
    {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    for (int i = 0; i < n/2; i++)
    {
        q.push(q.front());
        q.pop();
    }

    for (int i = 0; i < n / 2; i++)
    {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty())
    {
        ans.push(st.top());
        ans.push(q.front());
        st.pop();
        q.pop();
    }
    
    return ans;
}

void display(queue<int> q)
{
    int n = q.size();
    for (int i = 0; i < n; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    queue<int> q;

    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);

    display(q);

    queue<int> ans = interleave(q);
    display(ans);
    queue<int>res=interleave2(q);
    display(res);

    return 0;
}