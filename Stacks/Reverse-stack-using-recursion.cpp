#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &s, int ele)
{

    if (s.empty())
    {
        s.push(ele);
        return;
    }

    int i = s.top();
    s.pop();
    insertAtBottom(s, ele);
    s.push(i);
}

void reverse(stack<int> &s)
{

    if (s.empty())
    {
        return;
    }

    int i = s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s, i);
}

int main()
{

    stack<int> s;
    s.push(3);
    s.push(4);
    s.push(7);
    s.push(9);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    s.push(3);
    s.push(4);
    s.push(7);
    s.push(9);

    reverse(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}