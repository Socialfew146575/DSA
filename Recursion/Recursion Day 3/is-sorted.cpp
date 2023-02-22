#include <bits/stdc++.h>
using namespace std;
// Create a function to check whether a given array is sorted or not

bool isSorted(int array[], int n)
{
    // base case
    if (n == 0 || n == 1)
    {
        return 1;
    }

    if (array[0] > array[1])
    {
        return false;
    }
    else
    {
        return isSorted(array + 1, n - 1);
    }
}

int main()
{
    int arr[] = {2, 4, 6, 9, 11, 13};

    cout << isSorted(arr, 6);

    return 0;
}