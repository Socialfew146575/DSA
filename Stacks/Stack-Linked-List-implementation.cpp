#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int d)
    {

        this->data = d;
        this->next = nullptr;
    }
};

class Stack
{

    Node *top;

public:
    Stack()
    {

        top = nullptr;
    }

    void push(int data)
    {

        Node *temp = new Node(data);
        if (!temp)
        {

            cout << "Stack Overflow" << endl;
            return;
        }

        temp->data = data;
        temp->next = top;
        top = temp;
    }

    void pop()
    {

        if (top == NULL)
        {

            cout << "Stack Underflow" << endl;
            return;
        }

        Node *temp = top;
        top = top->next;
        delete temp;
    }

    bool isEmpty()
    {

        return top == NULL;
    }

    int peek()
    {

        if (isEmpty())
        {

            cout << "Stack is empty" << endl;
            return -1;
        }
        else
        {
            return top->data;
        }
    }

    void display()
    {

        Node *temp;

        if (top == nullptr)
        {
            cout << "Stack is empty" << endl;
            exit(1);
        }
        else
        {
            temp = top;
            while (temp != NULL)
            {
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
    }
};

int main()
{
    Stack st;
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);

    st.display();

    cout << st.peek() << endl;

    st.pop();
    st.pop();
    st.display();

    return 0;
}