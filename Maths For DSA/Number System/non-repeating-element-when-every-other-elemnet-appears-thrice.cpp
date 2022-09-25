#include <bits/stdc++.h>
using namespace std;

int nonRepeating(int array[], int n)
{

    int count[32] = {0};

    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (array[j] & (1 << i))
            {
                count[i]++;
            }
        }
    }

    int res = 0;

    for (int i = 0; i < 32; i++)
    {
        res += (count[i] % 3) * (1 << i);
    }
    return res;
}

int main()
{
    int array[] = {2, 2, 3, 2, 7, 7, 8, 7, 8, 8};

    cout << nonRepeating(array, 10);

    return 0;
}