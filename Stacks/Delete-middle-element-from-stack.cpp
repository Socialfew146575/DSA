#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &inputStack, int size, int count)
{

    if (count == size / 2)
    {
        inputStack.pop();
        return;
    }

    int i = inputStack.top();
    inputStack.pop();
    solve(inputStack, size, count + 1);
    inputStack.push(i);
}

void deleteMiddle(stack<int> &inputStack, int N)
{
    int count = 0;
    solve(inputStack, N, count);
}

int main()
{

    stack<int> st;
    st.push(5);
    st.push(9);
    st.push(12);
    st.push(8);
    st.push(4);

    deleteMiddle(st, st.size());

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}