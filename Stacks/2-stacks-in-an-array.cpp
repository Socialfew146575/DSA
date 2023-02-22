#include <bits/stdc++.h>
using namespace std;

class Twostack
{

public:
    int *arr;
    int top1;
    int top2;
    int size;

    Twostack(int s)
    {

        this->size = s;
        arr = new int[s];
        this->top1 = -1;
        this->top2 = s;
    }

    void push1(int ele)
    {

        if (top2 - top1 > 1)
        {

            top1++;
            arr[top1] = ele;
        }
        else
        {
            cout << "Stack Overflow" << endl;
            return;
        }
    }

    void push2(int ele)
    {
        if (top2 - top1 > 1)
        {

            top2--;
            arr[top2] = ele;
        }
        else
        {
            cout << "Stack Overflow" << endl;
            return;
        }
    }

    void pop1()
    {

        if (top1 >= 0)
        {
            top1--;
        }
        else
        {
            cout << "Stack Underflow" << endl;
            return;
        }
    }

    void pop2()
    {

        if (top2 < size)
        {

            top2++;
        }
        else
        {
            cout << "Stack Underflow" << endl;
            return;
        }
    }

    int peek1()
    {

        if (top1 >= 0)
            return arr[top1];
        else
            return -1;
    }
    int peek2()
    {

        if (top2 < size)
            return arr[top2];
        else
            return -1;
    }
};

int main()
{

    Twostack st(5);

    st.push1(5);
    st.push1(4);
    st.push2(1);
    st.push2(2);
    st.push1(3);

    cout << st.peek1() << " ";
    st.pop1();
    cout << st.peek2() << "\n";
    st.pop2();
    cout << st.peek1() << " ";
    st.pop1();
    cout << st.peek2() << "\n";
    st.pop2();
    cout << st.peek1() << " ";
    st.pop1();
   

    return 0;
}