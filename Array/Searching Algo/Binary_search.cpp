#include <iostream>
using namespace std;
int binary_search(int array[], int size, int key)
{       
    // Works in sorted array



    int start = 0;
    int end = size - 1;
    while (start <= end)
    { 
        //   int mid=(start+end)/2
        int mid = start+(end-start)/2;

        if (array[mid] == key)
        {
            return mid;
        }

        else if (array[mid] < key)
        {
            start = mid + 1;
        }

        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int array[6] = {3, 7, 11, 13, 19, 27};
    cout << "Is 27 present in the array or not? If present at which index:->"<< binary_search(array, 6,27)<<endl;
    cout << "Is 10 present in the array or not? If present at which index:->"<< binary_search(array, 6,10)<<endl;

     
    return 0;
}