#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i)
{

    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    int size = n;
    while (size > 1)
    {
        swap(arr[size], arr[1]);
        size--;

        heapify(arr, size, 1);
    }
}

int main()
{
    int arr[] = {-1, 55, 70, 50, 45, 60};
    heapSort(arr, 5);
    for (int i = 1; i <= 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}