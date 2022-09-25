#include <bits/stdc++.h>
using namespace std;

double NewtonSQRT(double n)
{
    double x = n;
    double root = 0;

    while (true)
    {
        root = 0.5 * (x + (n / x));

        if (fabs(root - x) < 1)
        {
            break;
        }

        x = root;
    }

    return root;
}

int main()
{
    cout << NewtonSQRT(40);

    return 0;
}