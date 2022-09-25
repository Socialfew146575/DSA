#include <bits/stdc++.h>
using namespace std;

void print(int *p)
{
    *p = *p + 1;
    p = p + 1;

    // cout << p;
}

int getSum(int *arr, int n)
{
    cout<<"Size :"<<sizeof(arr)<<endl;//=> output : 4==>But this is size of a pointer.Hence This is passed as a pointer in the function.
    // int arr[]=int *arr;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    return sum;
}

int main()
{
    // int val = 5;
    // int *p = &val;

    // cout << "Value of p before " << p << endl;
    // cout << "Value of *p before " << *p << endl;
    // print(p);
    // cout << "Value of p after " << p << endl;
    // cout << "Value of *p after " << *p << endl;

    int arr[] = {1, 2, 3, 4, 5,6};

    cout << "Sum is " << getSum(arr+3, 3) << endl;

    return 0;
}