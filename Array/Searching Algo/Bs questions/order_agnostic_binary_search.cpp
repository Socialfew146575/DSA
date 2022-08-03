#include <bits/stdc++.h>
using namespace std;

int binary_search(int array[],int size,int target){
    int s=0;
    int e=size-1;
    if(array[s]>array[e]){
        while (s<=e){ 
        int mid=s+(e-s)/2;
          if(target > array[mid]){
            e=mid-1;

        }else if(target <array[mid]){
            s=mid+1;
        }else{
            return mid;
        }
            
        }
        
    }
    else{
             while (s<=e){ 
        int mid=s+(e-s)/2;
          if(target < array[mid]){
            e=mid-1;

        }else if(target >array[mid]){
            s=mid+1;
        }else{
            return mid;
        }
            
        }
        

    }
    return -1;
}

int main(){

    int array[1000]={0};
    int size;
    cin>>size;
    for (int i = 0; i < size; i++)
    {
       cin>>array[i];
    }
    
    cout<<binary_search(array,size,20);
return 0;
}