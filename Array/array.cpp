#include <bits/stdc++.h>

using namespace std;

void sort_0_1(int array[], int size)
{
    int start = 0;
    int end = size - 1;
    while (start < end)
    {
        if (array[start] == 1 && array[end] == 0)
        {
            swap(array[start], array[end]);
            start++;
            end--;
        }
        else if (array[end]==1)
        {

            end--;
        }

        else if (array[start]==0)
        {
            start++;
        }
    }
}

void triplet_sum(int arr[], int size, int sum)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            for (int k = j + 1; k < size; k++)
            {

                if (arr[i] + arr[j] + arr[k] == sum)
                {
                    cout << arr[i] << " " << arr[j] << " " << arr[k];
                    cout << endl;
                }
            }
        }
    }
}
void pair_sum(int arr[], int size, int sum)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] + arr[j] == sum)
            {
                cout << arr[i] << " " << arr[j];
                cout << endl;
            }
        }
    }
}

void intersection(int a[], int b[], int size_a, int size_b)
{
    //    Brute Force

    // for (int i = 0; i < size_a; i++)
    // {
    //     for (int j = 0; j < size_b; j++)
    //     {
    //         if (a[i] ==b[j])
    //         {
    //             cout << a[i]<<" ";
    //             b[j] = INT32_MIN;
    //             break;
    //         }
    //     }
    // }

    // optimized
    // for (int i = 0; i < size_a; i++)
    // {
    //     for (int j = 0; j < size_b; j++)
    //     {
    //         if(a[i]<b[j]){
    //             break;
    //         }

    //         else if(a[i]==b[j]){
    //             cout<<a[i]<<" ";
    //             b[j]=INT32_MIN;
    //             break;
    //         }
    //     }

    // }

    // more optimized--Two pointer Approach
    int i = 0;
    int j = 0;
    while (i < size_a && j < size_b)
    {
        if (a[i] < b[j])
        {
            i++;
        }
        else if (a[i] == b[j])
        {
            cout << a[i] << " ";
            i++, j++;
        }
        else
        {
            j++;
        }
    }
}

void duplicate(int array[], int size)
{
    // {       Brute Force
    // int sum = 0;
    // int sum2 = (size - 1) * (size) / 2;
    // for (int i = 0; i < size; i++)
    // {
    //     sum = sum + array[i];
    // }
    // cout << sum - sum2;

    // Optimized
    int res = 0;
    for (int i = 0; i < size; i++)
    {
        res = res ^ array[i];
    }

    for (int i = 0; i < size; i++)
    {
        res = res ^ i;
    }
    cout << res;
}
void unique_element(int array[], int size)
{
    int res = 0;
    for (int i = 0; i < size; i++)
    {
        res = res ^ array[i];
    }
    cout << res;
}
void swap_alternate(int array[], int size)
{
    for (int i = 0; i < (size - 1); i = i + 2)
    {
        swap(array[i], array[i + 1]);
    }
}

int sum(int arr[], int size)
{
    int res = 0;
    for (int i = 0; i < size; i++)
    {
        res = res + arr[i];
    }
    return res;
}
void reversearray(int arr[], int size)
{
    for (int i = 0, j = size - 1; i <= j; i++, j--)
    {
        swap(arr[i], arr[j]);
    }
}
bool linearsearch(int array[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == key)
        {
            return 1;
        }
    }
    return 0;
}
int getmax(int arr[], int size)
{
    int maxi = INT32_MIN;
    for (int i = 0; i < size; i++)
    {
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

int getmin(int arr[], int size)
{
    int mini = INT32_MAX;
    for (int i = 0; i < size; i++)
    {
        mini = min(mini, arr[i]);
    }
    return mini;
}

void inputArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int array[1000];

    inputArray(array, n);
    // printArray(array, n);
    // cout << "Maximum element in the array is "
    //      << getmax(array, n) << endl;
    // cout << "Mninimum element in the array is "
    //      << getmin(array, n) << endl;

    // int key;
    // cin >> key;
    // cout << "Does element " << key << " is present in the array? " << linearsearch(array, n, key) << endl;

    // reversearray(array, n);
    // printArray(array, n);

    // cout << "The summation of the entire array elements is " << sum(array, n) << endl;
    // swap_alternate(array, n);
    // printArray(array, n);

    // unique_element(array, n);

    // duplicate(array,n);
    // int m;
    // cin >> m;
    // int array2[m];
    // inputArray(array2, m);

    // intersection(array, array2, n, m);
    // int sum;
    // cin >> sum;
    // pair_sum(array,n,sum);
    // triplet_sum(array, n, sum);

    sort_0_1(array, n);
    printArray(array, n);

    return 0;
}