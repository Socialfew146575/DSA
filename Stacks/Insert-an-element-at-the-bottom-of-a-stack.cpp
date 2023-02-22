#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &st, int ele)
{
    if (st.empty())
    {

        st.push(ele);
        return;
    }

    int c = st.top();
    st.pop();
    solve(st, ele);
    st.push(c);
}

void insert(stack<int> &st, int ele)
{

    
   

    solve(st, ele);
}

int main()
{

    stack<int> st;
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    insert(st, 1);
    while (!st.empty())
    {
        cout << st.top() << "\n";
        st.pop();
    }

    return 0;
}