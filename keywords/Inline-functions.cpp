#include <bits/stdc++.h>
using namespace std;
// Normal function
// int getMax(int &a, int &b)
// {

//     return a > b ? a : b;
// }

// Inline Functions
inline int getMax(int &a, int &b)
{

    return (a > b) ? a : b;
}

int main()
{

    int a = 1, b = 2;
    int ans = 0;

    // ans = (a > b) ? a : b;
    cout << getMax(a, b) << endl;
    a = a + 3;
    b = b + 1;
    // ans = (a > b) ? a : b;
    cout << getMax(a, b) << endl;
    return 0;
}