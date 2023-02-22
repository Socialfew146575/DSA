#include <bits/stdc++.h>
using namespace std;

void solve1(vector<int> arr)
{
    int count = 0;

    for (int i = 1; i < arr.size() - 1; i++)
    {
        int mx1 = INT_MIN, mx2 = INT_MIN;
        for (int j = i; j >= 0; j--)
        {
            mx1 = max(mx1, arr[j]);
        }
        for (int j = i; j < arr.size(); j++)
        {
            mx2 = max(mx2, arr[j]);
        }
        int mn = min(mx1, mx2);

        count += mn - arr[i];
    }

    cout << count << " ";
}

void solve2(vector<int> arr)
{
    int count = 0;
    vector<int> maxL(arr.size());
    vector<int> maxR(arr.size());
    maxL[0] = arr[0];
    maxR[arr.size() - 1] = arr[arr.size() - 1];
    for (int i = 1; i < arr.size(); i++)
    {
        maxL[i] = max(arr[i], maxL[i - 1]);
    }
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        maxR[i] = max(maxR[i + 1], arr[i]);
    }
    for (int i = 1; i < arr.size() - 1; i++)
    {
        count += min(maxL[i], maxR[i]) - arr[i];
    }

    cout << count << endl;
}

int main()
{

    vector<int> arr1 = {3, 0, 0, 2, 0, 4};

    solve1(arr1);
    solve2(arr1);
    vector<int> arr2 = {2, 0, 2};

    solve1(arr2);
    solve2(arr2);

    return 0;
}