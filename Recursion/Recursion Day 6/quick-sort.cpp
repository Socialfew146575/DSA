#include <bits/stdc++.h>
using namespace std;

void sort(int *arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int s = low;
    int e = high;

    int m = s + (e - s) / 2;
    int pivot = arr[m];

    while (s <= e)
    {
        while (arr[s] < pivot)
        {
            s++;
        }
        while (arr[e] > pivot)
        {
            e--;
        }

        if (s <= e)
        {
            swap(arr[s], arr[e]);
            s++;
            e--;
        }
    }
    

    sort(arr, low, e);
    sort(arr, s, high);
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    sort(arr, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}