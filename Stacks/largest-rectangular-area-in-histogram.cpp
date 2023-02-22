#include <bits/stdc++.h>
using namespace std;

int bruteForce(vector<int> arr)
{
    int n = arr.size();

    int mx = -1;
    for (int i = 0; i < n; i++)
    {
        int count = 1;

        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
                break;

            count++;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
                break;

            count++;
        }

        int area = count * arr[i];
        mx = max(mx, area);
    }

    return mx;
}
vector<int> nextSmallerElements(vector<int> heights, int n)
{

    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = heights[i];

        while (s.top() != -1 && heights[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}
vector<int> prevSmallerElements(vector<int> heights, int n)
{

    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int curr = heights[i];

        while (s.top() != -1 && heights[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

int largestRectangularArea(vector<int> &heights)
{

    int n = heights.size();

    vector<int> next(n);
    vector<int> prev(n);
    next = nextSmallerElements(heights, n);
    prev = prevSmallerElements(heights, n);
    int mx = -1;
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];

        if (next[i] == -1)
            next[i] = n;
        int b = next[i] - prev[i] - 1;
        int area = l * b;
        mx = max(mx, area);
    }

    return mx;
}

int main()
{
    vector<int> arr;

    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(2);
    arr.push_back(3);

    cout << "Largest rectangular area in Histogram is " << bruteForce(arr) << endl;
    cout << "Largest rectangular area in Histogram is " << largestRectangularArea(arr) << endl;

    return 0;
}