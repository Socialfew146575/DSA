#include <bits/stdc++.h>
using namespace std;
void sort(int *arr, int n, int index)
{

    if (index == n)
    {
        return;
    }

    for (int i = index; i > 0; i--)
    {
        if (arr[index] < arr[i - 1])
        {
            swap(arr[i], arr[i - 1]);
            index = i - 1;
        }
    }

    sort(arr, n, ++index);
}
void insertionSortRecursive(int arr[], int n)
{
    // Base case
    if (n <= 1)
        return;

    // Sort first n-1 elements
    insertionSortRecursive(arr, n - 1);

    // Insert last element at its correct position
    // in sorted array.
    int last = arr[n - 1];
    int j = n - 2;

    /* Move elements of arr[0..i-1], that are
    greater than key, to one position ahead
    of their current position */
    while (j >= 0 && arr[j] > last)
    {   
    
        arr[j + 1] = arr[j];
        j--;
       
    }
    arr[j + 1] = last;
}

int main()
{
    // int arr[] = {12, 11, 13, 5, 6};
    // int n = sizeof(arr)/sizeof(arr[0]);

    // sort(arr, n, 1);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    cout<<endl;
   int array[] = {12, 11, 13, 5, 6};
    int n = sizeof(array)/sizeof(array[0]);
    insertionSortRecursive(array, n);
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}