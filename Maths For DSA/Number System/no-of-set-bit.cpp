
#include <bits/stdc++.h>
using namespace std;

int no_of_SetBit(int n)
{
    int count = 0;
    while (n > 0)
    {
        n = n & (n - 1);
        count++;
    }

    return count;
}

int main()
{
    cout << no_of_SetBit(7);


    return 0;
}