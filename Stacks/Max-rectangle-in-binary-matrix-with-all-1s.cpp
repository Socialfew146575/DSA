#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(int *heights, int n)
{

    vector<int> ans(n);
    stack<int> s;
    s.push(-1);

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
vector<int> prevSmallerElement(int *heights, int n)
{

    vector<int> ans(n);
    stack<int> s;
    s.push(-1);

    for (int i = 0; i< n; i++)
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

int largestRectangularArea(int *heights, int n)
{

    int area = INT_MIN;
    vector<int> next = nextSmallerElement(heights, n);
    vector<int> prev = prevSmallerElement(heights, n);

    for (int i = 0; i < n; i++)
    {
        int l = heights[i];
        if (next[i] == -1)
            next[i] = n;

        int b = next[i] - prev[i] - 1;

        int newArea = l * b;
        area = max(area, newArea);
    }

    return area;
}

int maxRectangle(int m[][4], int row, int col)
{

    int area = largestRectangularArea(m[0], col);

    for (int i = 1; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (m[i][j] != 0)
                m[i][j] += m[i - 1][j];
            else
                m[i][j] = 0;
        }
        int newArea = largestRectangularArea(m[i], col);
        area = max(area, newArea);
    }

    return area;
}

int main()
{

    int m[4][4] = {{0, 1, 1, 0},
                   {1, 1, 1, 1},
                   {1, 1, 1, 1},
                   {1, 1, 0, 0}};

    cout << maxRectangle(m, 4, 4) << endl;
    int n[4][4] = {{1, 1, 1, 1},
                   {1, 1, 1, 1},
                   {1, 1, 1, 1},
                   {1, 1, 1, 1}};

    cout << maxRectangle(n, 4, 4) << endl;

    return 0;
}