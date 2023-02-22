#include <bits/stdc++.h>
using namespace std;

bool palindrome(int n, int s, int e)
{
    string str = to_string(n);

    if (s > e)
    {
        return true;
    }
   
    if (str[s] != str[e])
    {
        return false;
    }
    else
    {
        return palindrome(n, ++s, --e);
    }
}

int main()
{

    cout << palindrome(12344321, 0, 7);
    return 0;
}