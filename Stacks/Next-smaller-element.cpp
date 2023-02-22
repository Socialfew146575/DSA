#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{

    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }

    return ans;
}

vector<int> previousSmallerElement(vector<int> &arr, int n)
{

    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (s.top() >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }

    return ans;
}

int main()
{

    vector<int> arr;

    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(3);
    for (int i : arr)
    {

        cout << i << " ";
    }
    cout << endl;
    vector<int> ans = nextSmallerElement(arr, 4);

    for (int i : ans)
    {

        cout << i << " ";
    }
    cout << endl;
    vector<int> res = previousSmallerElement(arr, 4);

    for (int i : res)
    {

        cout << i << " ";
    }
    return 0;
}