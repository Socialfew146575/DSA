#include <bits/stdc++.h>
using namespace std;

void bSort(int arr[], int n)
{

    if (n == 0 || n == 1)
    {
        return;
    }

    for (int i = 0; i < n-1; i++)
    {
        if (arr[i] > arr[i + 1])
        {

            swap(arr[i], arr[i + 1]);
        }
    }

    bSort(arr, n - 1);
}

int main()
{

    int array[] = {2, 5, 1, 6, 9};
    bSort(array, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}