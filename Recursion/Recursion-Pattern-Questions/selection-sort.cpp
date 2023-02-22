#include <bits/stdc++.h>
using namespace std;

void selectionSort(int *arr, int n, int c, int max)
{

    if (n == 1)
    {
        return;
    }

    if (c < n)
    {   
        
       
        if (arr[c] > arr[max])
        {   
            selectionSort(arr, n, c+1, c);
        }
        else
        {
            selectionSort(arr, n, c+1, max);
        }
    }
    else
    {   
        swap(arr[n - 1], arr[max]);
        selectionSort(arr, n-1, 0, 0);
    }
}

int main()
{
     int arr[]={4,3,5,1,2};

    selectionSort(arr,5,0,0);

    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}