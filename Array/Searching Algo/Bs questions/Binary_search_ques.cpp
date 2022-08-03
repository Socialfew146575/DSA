#include <iostream>
using namespace std;
// peak index in mountain array
void peak_index(int array[], int size)
{
    int start = 0;
    int end = size - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (array[mid] > array[mid + 1] && array[mid] > array[mid - 1])
        {
            cout << array[mid] << " at " << mid;
            return;
        }
        else if (array[mid] > array[mid + 1])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
}
// Find the first and last position of an element stored in an array..
int leftmost_position(int array[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (array[mid] == key)
        {
            ans = mid;
            end = mid - 1;
        }
        if (array[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = start + 1;
        }
    }
    return ans;
}
int rightmost_position(int array[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (array[mid] == key)
        {
            ans = mid;
            start = mid + 1;
        }
        if (array[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = start + 1;
        }
    }
    return ans;
}

int main()
{

    // int even[6] = {1, 2, 3, 3, 3, 4};
    // cout << "First occurence of element 3 is " << endl;
    // int a = leftmost_position(even, 6, 3);
    // cout << a << endl;
    // cout << "last occurence of element 3 is " << endl;
    // int b = rightmost_position(even, 6, 3);
    // cout << b;
    // cout << endl;
    // cout << "Total no. of occurence:->" << (b-a) + 1<<endl;

    int mountain[5] = {3,5,3,2,0};
    peak_index(mountain, 5);
    return 0;
}