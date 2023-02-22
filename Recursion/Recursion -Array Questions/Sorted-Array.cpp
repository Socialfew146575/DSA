

#include <bits/stdc++.h>
using namespace std;

bool isSorted(int *arr, int n)
{

    if (n == 1)
    {
        return true;
    }

    // if (arr[n - 1] < arr[n - 2])
    // {
    //     return false;
    // }
    // else
    // {
    //     return isSorted(arr, n - 1);
    // }

    return (arr[n - 1] > arr[n - 2]) && isSorted(arr, n - 1);
}

int main()
{

    int arr[] = {1, 2, 4, 3, 9, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << isSorted(arr, n) << endl;
    int array[] = {1, 2, 4, 8, 9, 12};
    int m = sizeof(array) / sizeof(array[0]);

    cout << isSorted(array, m);
    return 0;
}