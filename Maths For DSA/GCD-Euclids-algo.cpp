#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{

    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }

    return a == 0 ? b : a;
}

int lcm(int a, int b)
{

    return a * b / gcd(a, b);
}
int main()
{
    cout << gcd(36, 60);
    cout << endl;
    cout << lcm(9, 18);
    return 0;
}