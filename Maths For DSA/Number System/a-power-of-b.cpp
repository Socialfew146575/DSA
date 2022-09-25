#include <bits/stdc++.h>
using namespace std;

int power(int a, int b)
{
    int ans = 1;
    int base = a;
    while (b > 0)
    {
        if (b & 1)
        {
            ans *= base;
        }

        base = base * base;
        b >>= 1;
    }

    return ans;
}

int main()
{
    cout << power(3, 6);

    return 0;
}