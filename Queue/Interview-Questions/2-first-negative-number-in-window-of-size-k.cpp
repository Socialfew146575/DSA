#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> arr, int k)
{

    int n = arr.size();
    int i = 0, j = 0;
    deque<int> d;
    vector<int> ans;
    while (j < n)
    {
        if (arr[j] < 0)
        {

            d.push_back(arr[j]);
        }

        if (j - i + 1 < k)
        {
            j++;
        }
        else
        {
            if (d.size() == 0)
                ans.push_back(0);
            else
                ans.push_back(d.front());

            if (arr[i] < 0)
            {
                d.pop_front();
            }
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{

    vector<int> arr = {-8, 2, 3, -6, 10};

    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<int> ans = solve(arr, 2);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}