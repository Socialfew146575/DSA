#include <iostream>
using namespace std;

void rotated_search(int array[],int size,int key){
    // To calculate pivot
    int start=0;
    int end=size-1;
    int mid;
    int pivot;
    while (start<end) {
      mid=start+(end-start)/2;
      if (array[mid]>=array[0]) {
        start=mid+1;
      }
      else
      {
        end=mid;
      }
    }
    pivot=start;

    int s,e;
    if (key>=array[0]) {
      s=0;
      e=pivot-1;

    }
    else{
      s=pivot;
      e=size-1;
    }
    while (s<=e) {
      mid=s+(e-s)/2;
      if (array[mid]==key) {
        cout<<mid;
        return;
      }
    else if (array[mid]>key) {
        e=mid-1;
      }
      else{
        s=mid+1;
      }
    }
    cout<<-1;

}

void pivot(int array[], int size)
{
    int start = 0;
    int end = size - 1;
    int mid;
    while (start <end)
    {
        mid = start + (end - start) / 2;
        if (array[mid] >= array[0])
        {
            start = mid+1;
        }

        else
        {
            end = mid;
        }
    }
    cout << array[start];
}
int main()
{
    int array[] = {2,0,2,3,4};

    // pivot(array, 8);
    pivot(array,5);



    return 0;
}
