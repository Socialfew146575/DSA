#include <bits/stdc++.h>
using namespace std;

bool linearSearch(int *arr, int n, int target)
{
    if (n == 0)
    {
        return false;
    }

    return arr[n - 1] == target || linearSearch(arr, n - 1, target);
}


int find(int *arr,int n,int target){

    if(n==0){
        return -1;
    }

    if(arr[n-1]==target){
        return n-1;
    }
    else{
        return find(arr,n-1,target);
    }


}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cin >> target;

     linearSearch(arr, n, target) ? cout << target << " is present in array at "<<find(arr,n,target)<<" index" : cout << target << " is not present in the array";

    return 0;
}