#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[10]={0,1,2,3,4,5,};

    // cout << "address of first memory block " << arr << endl;
    // cout << "address of first memory block " << &arr[0] << endl;
    // cout<<*arr<<endl;
    // cout<<*arr+1<<endl;
    // cout<<*(arr+1)<<endl;
    // cout<<arr[3]<<endl;
    // cout<<3[arr]<<endl;

    int *ptr=&arr[0];
    cout<<sizeof(arr)<<endl;
    cout<<sizeof(ptr)<<endl;
    cout<<sizeof(&ptr)<<endl;

    return 0;
}