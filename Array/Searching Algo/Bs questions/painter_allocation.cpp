#include <iostream>
using namespace std;

bool isPossible(int array[], int size, int k, int mid)
{
    int painterCount = 1;
    int painterBoards = 0;
    for (int i = 0; i < size; i++)
    {
        if (painterBoards + array[i] <= mid)
        {
            painterBoards += array[i];
        }

        else
        {
            painterCount++;
            if (painterCount > k || array[i] > mid)
            {
                return false;
            }
            painterBoards = array[i];
        }
    }
    return true;
}

int painter_allocation(int array[], int size, int k)
{
    int s = 0;
    int e = 0;
    for (int i = 0; i < size; i++)
    {
        e = e + array[i];
    }
    int mid;
    int ans = -1;
    while (s < e)
    {
        mid = s + (e - s) / 2;
        if (isPossible(array, size, k, mid))
        {
            ans = mid;
            e = mid - 1;
        }

        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int array[4] = {5, 5, 5, 5};
    cout << painter_allocation(array, 4, 2);

    return 0;
}