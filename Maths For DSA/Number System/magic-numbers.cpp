#include <bits/stdc++.h>
using namespace std;

int magicNumber(int n)
{

    int res = 0;
    int base = 5;
    while (n > 0)
    {
        int last = n & 1;

        n = n >> 1;

        res += last * base;
        base *= 5;
    }

    return res;
}

int main()
{
    cout << magicNumber(3);
    return 0;
}
