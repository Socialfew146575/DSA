
#include <bits/stdc++.h>
using namespace std;

int sum(int n)
{

    return 1 << n - 1;
}

int main()
{

    int n;
    cin >> n;

    cout << sum(n);

    return 0;
}