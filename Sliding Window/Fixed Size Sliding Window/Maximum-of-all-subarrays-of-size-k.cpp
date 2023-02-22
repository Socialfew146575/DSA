#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> arr, int k)
{
    vector<int> ans;
    int n = arr.size();

    int i = 0, j = 0;

    int max = INT_MIN;
    deque<int> d;
    cout << endl;
    while (j < n)
    {
        while (d.size() > 0 && d.back() < arr[j])
        {
            d.pop_back();
        }
        d.push_back(arr[j]);
       
        if (j - i + 1 < k)

            j++;
        else
        {
            ans.push_back(d.front());
            if (arr[i] == d.front())
            {
                d.pop_front();
            }

            i++;
            j++;
        }
    }
    cout << endl;
    return ans;
}

int main()
{

    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    int k = 3;
    vector<int> ans = solve(arr, k);

    for (int i : ans)
    {
        cout << i << " ";
    }

    return 0;
}