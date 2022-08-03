#include <iostream>
using namespace std;

void selection_sort(int array[],int size){
   
    
    for (int i = 0; i < size; i++)
      
    { int minIndex=i;
         for (int j = i+1; j < size; j++)
    {   
        if (array[j]<array[minIndex])
        {
            minIndex=j;
        }
        
          


    }
    swap(array[minIndex],array[i]);
    
    
    }
    
}

void selection_sort2(int array[],int size){
    for (int i = 0; i < size; i++)
    {   int maxIndex=i;
        for (int j = i+1 ; j < size; j++)
        {   if (array[j]>array[maxIndex])
        {
            maxIndex=j;
        }
        
            
        }
        swap(array[maxIndex],array[i]);
        
    }
    
}

int main(){
int array[]={4,5,1,2,3};
selection_sort(array,5);
for (int i = 0; i < 5; i++)
{
    cout<<array[i]<<" ";
}
cout<<endl;
selection_sort2(array,5);
for (int i = 0; i < 5; i++)
{
    cout<<array[i]<<" ";
}

return 0;
}