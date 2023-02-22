#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr, int n, int k)
{

    int i = 0, j = 0;
    int mx = -1;
    int sum = 0;

    while (j < n)
    {

        sum += arr[j];
        if (sum < k)
        {
            j++;
        }

        else if (sum == k)
        {

            int len = j - i + 1;
            mx = max(mx, len);
            j++;
        }
        else
        {

            while (sum > k)
            {
                sum -= arr[i];
                i++;
            }
            if (sum == k)
            {

                int len = j - i + 1;
                mx = max(mx, len);
            }
            j++;
        }
    }

    return mx;
}

int main()
{

    int n = 7;
    vector<int> arr = {4, 1, 1, 1, 2, 3, 5};
    int k = 5;

    cout << solve(arr, n, k) << endl;
    int m = 7;
    vector<int> ar = {2, 2, 2, 2, 2, 2, 5};
    // int k = 5;

    cout << solve(ar, m, k);

    return 0;
}