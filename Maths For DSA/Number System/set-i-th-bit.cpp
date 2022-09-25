#include <bits/stdc++.h>
using namespace std;

int setBit(int n, int i)
{
    int mask = 1 << i - 1;

    return n | mask;
}

int main()
{
    cout<<setBit(86,4);
    return 0;
}