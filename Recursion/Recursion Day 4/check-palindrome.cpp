#include <bits/stdc++.h>
using namespace std;

bool check(string &s, int i)
{

    if (i > s.length() - i - 1)
    {

        return true;
    }

    if (s[i] != s[s.length() - i - 1])
    {

        return false;
    }
    else
    {

        return check(s, i + 1);
    }
}

int main()
{
    string s = "abbccbba";
    cout << check(s, 0);

    return 0;
}