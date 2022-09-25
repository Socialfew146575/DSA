#include <bits/stdc++.h>
using namespace std;

int numberOfDigits(int n, int b)
{

    return log(n)/log(b)+1;
}

int main()
{
    cout<<numberOfDigits(6,2);
    return 0;
}