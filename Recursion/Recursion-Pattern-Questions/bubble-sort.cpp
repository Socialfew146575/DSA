#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int *arr,int n,int c){

    if(n==1){
        return;
    }

    if(c<n-1){

        if(arr[c]>arr[c+1]){
            swap(arr[c],arr[c+1]);
        }

        bubbleSort(arr,n,++c);


    }
    else{

        bubbleSort(arr,--n,0);

    }


}


int main(){

    int arr[]={4,3,5,1,2};

    bubbleSort(arr,5,0);

    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    

return 0;
}