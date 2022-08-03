#include <iostream>
using namespace std;
void insertion_sort(int array[],int size){
    for (int i = 1; i < size; i++)
    {   int j=i-1;
    int temp=array[i];
        while (j>=0)
        {
            if(array[j]>temp){
                array[j+1]=array[j];
            }

            else{
                break;
            }

            j--;
        }

        array[j+1]=temp;
        
    }
    
}
int main(){
    int array[]={5,4,3,2,1,0};

    insertion_sort(array,6);
    for (int i = 0; i < 6; i++)
    {
        cout<<array[i]<<" ";
    }
    
return 0;
}