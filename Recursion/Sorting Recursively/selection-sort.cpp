#include <bits/stdc++.h>
using namespace std;

void sort(int *arr,int n){

    if(n==1){
        return;
    }

    int mini=arr[0];
    int index=0;
    for (int i = 0; i < n; i++)
    {
        if(mini>arr[i]){
            mini=arr[i];
            index=i;
        }
    }
    swap(arr[0],arr[index]);

    sort(arr+1,n-1);

    

}


int main(){

    int arr[]={4,5,1,2,3};

    sort(arr,5);

    for (int i = 0; i < 5; i++)
    {
            cout<<arr[i]<<" ";
    }
    


return 0;
}