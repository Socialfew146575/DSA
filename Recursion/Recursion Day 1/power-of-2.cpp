#include <bits/stdc++.h>
using namespace std;
int power(int m)
{
    // base case
    if (m == 0)
    {
        return 1;
    }

    // recursive relation
    return 2 * power(m - 1);
}
int main()
{

    int m;
    cin >> m;

    int res = power(m);

    cout << res << endl;
    return 0;
}