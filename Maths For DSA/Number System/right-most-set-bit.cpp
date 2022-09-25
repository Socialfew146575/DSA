#include <bits/stdc++.h>
using namespace std;

int r_SetBit(int n)
{
    // int count = 1;
    // while (n > 0)
    // {
    //     if (n & 1)
    //     {
    //         return count;
    //     }

    //     count++;
    //     n >>= 1;
    // }


    return log2(n&(-n))+1;
}

int main()
{
    cout << r_SetBit(4);
    cout << endl;

    return 0;
}