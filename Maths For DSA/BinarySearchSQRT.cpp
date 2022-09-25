#include <bits/stdc++.h>
using namespace std;

double BSsqrt(int n, int p)
{

    int s = 0;
    int e = n;
    double root = 0;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (mid * mid == n)
        {
            return mid;
        }

        else if (mid * mid > n)
        {
            e = mid - 1;
        }
        else
        {
            root = mid;
            s = mid +1;
        }
    }

    
    double factor = 1;
    for (int i = 0; i < p; i++)
    {
        factor /= 10;

        for (double j = root; j * j < n; j += factor)
        {
            root = j;
        }
    }
    return root;
}

int main()
{
    cout << BSsqrt(40, 3);
    return 0;
}