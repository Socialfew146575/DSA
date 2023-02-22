#include <bits/stdc++.h>
using namespace std;

void linearSearch(int *arr, int n, int key)
{

    if (n <= 0)
    {
        cout << "Not found";
        return;
    }

    if (arr[0] == key)
    {
        cout << "Found";
        return;
    }
    else
    {
        linearSearch(arr + 1, n - 1, key);
    }
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5};

    linearSearch(arr, 5, 3);
    return 0;
}