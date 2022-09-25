#include <bits/stdc++.h>
using namespace std;
void counting(int n)
{ // base case
    if (n == 0)
    {
        return;
    }

    // Recursive Relation
    counting(n - 1);

    cout << n << " ";
}
int main()
{
    int l;
    cin >> l;
    counting(l);
    return 0;
}