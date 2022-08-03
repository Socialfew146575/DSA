#include <iostream>
#include<math.h>
using namespace std;

int Bs_infinite(int array[],int target){
    int s=0;
    int e=1;
    int count=1;
    while (target>array[e])
    {
        int temp=e+1;
        e=e+(e-s+1)*2;
        s=temp;

    }


    while (s<=e)
    {   int mid=s+(e-s)/2;
        if(array[mid]>target){
            e=mid-1;
        
        }
        else if (array[mid]<target){
            s=mid+1;
          
        }
        else{
            array[mid]==target;
     
        return mid;
        

        }
       
    }
    
    return -1;
    
    
}

int main(){
    int array[]={3,5,7,9,10,90,100,130,140,160,170};
    cout<<Bs_infinite(array,10);
return 0;
}