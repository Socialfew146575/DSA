#include <bits/stdc++.h>
using namespace std;

int main()
{

    string str = "sfswfkldf";
    stack<char> s;

    for (char i : str)
    {
        s.push(i);
    }

    string ans = "";

    while (!s.empty())
    {

        char ch = s.top();
        ans += ch;
        s.pop();
    }


cout<<"Original string "<<str<<endl;
cout<<"Reversed string "<<ans<<endl;

    return 0;
}