#include <bits/stdc++.h>
using namespace std;

bool binarySearch(int *arr, int s, int e, int key)
{

    if (s>e)
    {
        return false;
    }
    int mid = s + (e - s) / 2;

    if (arr[mid] == key)
    {
        return true;
    }
    
    if (arr[mid] < key)
    {
        return binarySearch(arr,mid+1,e, key);
    }
    else
    {
        return binarySearch(arr, s,mid-1, key);
    }
}

int main()
{

    int array[] = {2, 4, 6, 10, 14, 16};

    cout << binarySearch(array,0,5, 10);

    return 0;
}