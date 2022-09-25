#include <bits/stdc++.h>
using namespace std;

// int fastPower(int a, int b)
// {

//     int res = 1;

//     while (b > 0)
//     {
//         if ((b & 1) != 0)
//         {
//             res = res * a;
//         }

//         a = a * a;
//         b = b>>1;
//     }
//     return res;
// }

///*************************** (a ^ b) % n****************************

    long long fastPower(long long a, long long b, int n)
{

    long long res = 1;

    while (b > 0)
    {
        if ((b & 1) != 0)
        {
            res = (res * a % n) % n;
        }

        a = (a % n * a % n) % n;
        b = b >> 1;
    }
    return res;
}

int main()
{
    // cout<<fastPower(3,5);
    // cout<<fastPower(212312324,5) =>OverFlow

    cout << fastPower(3978432, 5, 1000000007);
    return 0;
}