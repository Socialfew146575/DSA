#include <bits/stdc++.h>
using namespace std;

void print(int *arr,int n,int start=0){

    for (int i = start; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}

int main(){

    int array[]={1,3,5,7,9};

    print(array,5);//Without start parameter
    print(array,5,3);//With start parameter

return 0;
}