#include <iostream>
using namespace std;


int pivot(int array[],int size){
    int s=0;
    int e=size-1;
    while (s<e)
    {   int mid=s+(e-s)/2;
        if(array[mid]>=array[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
    }
   
    return s;

    
}










int main(){
    int array[]={4,5,6,7,0,1,2};
    cout<<pivot(array,7);
return 0;
}




