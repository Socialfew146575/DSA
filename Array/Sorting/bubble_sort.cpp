#include <iostream>
using namespace std;
void bubble_sort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
            }
            // for (int i = 0; i < size; i++)
            // {
            //     cout << array[i] << " ";
            // }
            // cout << endl;
        }
    }
}

void bubble_sort2(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] < array[j + 1])
            {
                swap(array[j], array[j + 1]);
            }
            // for (int i = 0; i < size; i++)
            // {
            //     cout << array[i] << " ";
            // }
            // cout << endl;
        }
    }
}
int main()
{
    int array[] = {3, 1, 5, 4, 2};
    bubble_sort(array, 5);
    for (int i = 0; i < 5; i++)
    {
        cout<<array[i]<<" ";
    }

    // cout<<endl;
    // bubble_sort2(array,5);
    // for (int i = 0; i < 5; i++)
    // {
    //     cout<<array[i]<<" ";
    // }

    return 0;
}