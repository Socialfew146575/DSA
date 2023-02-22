#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> arr, int k)
{

    int i = 0, j = 0;
    int n = arr.size();
    deque<int> mx;
    deque<int> mn;
    vector<int> ans;
    while (j < n)
    {   
        while (!mx.empty() && arr[j] > mx.back())
        {
            mx.pop_back();
        }
        mx.push_back(arr[j]);
        while (!mn.empty() && arr[j] < mn.back())
        {
            mn.pop_back();
        }
        mn.push_back(arr[j]);

        if (j - i + 1 < k)
        {
            j++;
        }

        else
        {

            ans.push_back(mx.front() + mn.front());
            if (mx.front() == arr[i])
                mx.pop_front();
            if (mn.front() == arr[i])
                mn.pop_front();

            i++;
            j++;
        }
    }
    return ans;
}

int main()
{

    vector<int> arr = {2, 5, -1, 7, -3, -1, -2};
    for (auto i : arr)
    {   
        cout << i << " ";
    }
    cout << endl;

    vector<int> ans = solve(arr, 4);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}