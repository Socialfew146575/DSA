#include <bits/stdc++.h>
using namespace std;


int sum(int array[], int n)
{

    // base case
    if (n <= 0)
    {
        return 0;
    }

    return (sum(array, n - 1) + array[n-1]);
}

int main()
{
    int array[] = {3, 2, 5, 1, 6};

    cout << sum(array, 5);

    return 0;
}