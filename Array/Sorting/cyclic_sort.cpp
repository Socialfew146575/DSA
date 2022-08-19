#include <iostream>
using namespace std;

void cyclic_sort(int array[], int n)
{
    int i = 0;
    while (i < n)
    {   int correct=array[i]-1;
        if (array[i]!= array[correct])
        {   swap(array[i],array[correct]);
        }
        else{
            i++;
        }
    }
}

int main()
{
    int array[5] = {5,4,3,2,1};
    cyclic_sort(array, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}