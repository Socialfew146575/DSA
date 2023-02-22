#include <bits/stdc++.h>
using namespace std;
int res = 1;
int power(int a, int b)
{

    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a;
    }

    int ans = power(a, b >> 1);
    if (b & 1)
    {

        return a * ans * ans;
    }

    else
    {

        return ans * ans;
    }
}

int main()
{
    int a = 2, b = 4;

    cout << power(a, b);
    return 0;
}