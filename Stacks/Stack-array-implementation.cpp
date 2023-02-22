#include <bits/stdc++.h>
using namespace std;

class Stack
{

public:
    // properties
    int top;
    int *arr;
    int size;

    Stack(int size)
    {

        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int ele)
    {

        if (top == size - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        else
        {
            top++;
            arr[top] = ele;
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack Underflow" << endl;
            return;
        }
    }

    int peek()
    {

        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    bool empty()
    {

        if (top == -1)
            return true;
        else
            return false;
    }
};

int main()
{
    Stack st(5);

    st.push(22);
    st.push(43);
    st.push(44);

    cout << st.peek() << endl;

    st.pop();
    cout << st.peek() << endl;

    st.pop();
    cout << st.peek() << endl;

    st.pop();
    cout << st.peek() << endl;

    
    return 0;
}