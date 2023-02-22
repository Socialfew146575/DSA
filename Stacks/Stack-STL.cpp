#include <bits/stdc++.h>
using namespace std;

int main()
{

    // creation of stack

    stack<int> s;

    // push operation
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout<<"size of stack is " <<s.size()<<endl;
    // pop operation
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();

    cout<<"Is stack empty "<<s.empty()<<endl;

    return 0;
}