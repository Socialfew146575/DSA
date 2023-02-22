#include <bits/stdc++.h>
using namespace std;

int product(int n)
{

    if (n == 1)
    {
        return 1;
    }

    return n * product(n - 1);
}

int main()
{

    cout << product(4);

    return 0;
}