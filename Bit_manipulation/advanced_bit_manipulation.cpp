#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    //   *****************Find the only non repeating element in an array where every element repeats twice*****************
    // int a[7] = {5, 4, 1, 4, 3, 5, 1};
    // int res = 0;
    // int n = 7;
    // for (int i = 0; i < 7; i++)
    // {
    //     res ^= a[i];
    // }
    // cout << res;

    // **************find the two non repeating elements in an array where every element repeats twice**************
    // int n;
    // cin >> n;
    // int a[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    // }
    // int res = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     res ^= a[i];
    // }
    // // cout << res;
    // int b = res;
    // int count = 0;
    // while (b != 0)
    // {
    //     if (b & 1)
    //     {
    //         count++;
    //         break;
    //     }

    //     b = b >> 1;
    // }
    // // cout << count;
    // int mask = 1 << (count - 1);
    // // cout << mask;
    // int temp = res;
    // for (int i = 0; i < n; i++)
    // {
    //     if ((a[i] & mask) == 0)
    //     {
    //         temp ^= a[i];
    //     }
    //     else
    //     {
    //         res = res ^ a[i];
    //     }
    // }
    // cout << temp << " ";

    // cout << res;

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int count[32] = {0};

    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((a[j] & (1 << i)) != 0)
            {
                count[i]++;
            }
        }
    }
    for (int i = 0; i < 32; i++)
    {

        cout << count[i] << " ";
    }
    int res = 0;
    // for (int i = 0; i < 32; i++)
    // {
    //     res += (count[i] % 3) * (1 << i);

    // }

    for (int i = 0; i < 32; i++)
    {
        count[i] = count[i] % 3;
        res += pow(2, i) * count[i];
    }

    cout << endl;
    cout << res;

    return 0;
    
}