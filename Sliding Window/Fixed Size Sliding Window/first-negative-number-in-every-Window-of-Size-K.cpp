#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> arr, int k)
{

    int n = arr.size();
    int i = 0, j = 0;

    deque<int> d;

    while (j < n)
    {
        if (arr[j] < 0)
            d.push_back(arr[j]);

        if (j - i + 1 < k)
        {
            j++;
        }
        else
        {
            if (d.size() == 0)
                cout << 0 << " ";
            else
            {
                cout << d[0] << " ";
                if (arr[i] < 0)
                    d.pop_front();
            }

            i++;
            j++;
        }
    }
}

int main()
{

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    solve(arr, k);

    return 0;
}