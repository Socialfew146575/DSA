#include <bits/stdc++.h>
using namespace std;

void insertSortingly(stack<int> &s, int ele)
{   
    if (s.empty() || s.top() < ele){
          s.push(ele);
          return;
    }
      
       
       
   

 

    int i = s.top();
   

    s.pop();
    insertSortingly(s, ele);
    s.push(i);
}

void sort(stack<int> &s)
{

    if (s.empty())
        return;

    int i = s.top();
    s.pop();
    sort(s);

    insertSortingly(s, i);
}

int main()
{

    stack<int> s;
    s.push(5);
    s.push(-2);
    s.push(9);
    s.push(-7);
    s.push(3);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
 
    s.push(5);
    s.push(-2);
    s.push(9);
    s.push(-7);
    s.push(3);

    sort(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}