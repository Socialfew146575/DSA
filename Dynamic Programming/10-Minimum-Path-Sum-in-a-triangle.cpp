// Given a triangle array, return the minimum path sum from top to bottom.

//     For each step,
//     you may move to an adjacent number of the row below.More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

#include <bits/stdc++.h>
using namespace std;

// FROM BOTTOM TO UP RECURSION   (i,j) to (0,0)

int solve(int i, int j, vector<vector<int>> &triangle)
{

    if (i == 0 && j == 0)
        return triangle[0][0];

    if (i < 0 || j < 0)
        return 1e9;

    int up = INT_MAX;
    int upLeft = INT_MAX;

    if (i != j)
        up = triangle[i][j] + solve(i - 1, j, triangle);
    if (j != 0)
        upLeft = triangle[i][j] + solve(i - 1, j - 1, triangle);

    return min(up, upLeft);
}

int minimumTotal(vector<vector<int>> &triangle)
{

    int i = triangle.size() - 1;
    int j = triangle[i].size();

    int mini = INT_MAX;
    for (int k = 0; k < j; k++)
    {
        mini = min(mini, solve(i, k, triangle));
    }

    return mini;
}
int solve2(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp)
{

    if (i == 0 && j == 0)
        return triangle[0][0];

    if (i < 0 || j < 0)
        return 1e9;

    if (dp[i][j] != -1)
        return dp[i][j];
    int up = INT_MAX;
    int upLeft = INT_MAX;

    if (i != j)
        up = triangle[i][j] + solve2(i - 1, j, triangle, dp);
    if (j != 0)
        upLeft = triangle[i][j] + solve2(i - 1, j - 1, triangle, dp);

    dp[i][j] = min(up, upLeft);
    return dp[i][j];
}

int minimumTotal2(vector<vector<int>> &triangle)
{

    int i = triangle.size() - 1;
    int j = triangle[i].size();
    vector<vector<int>> dp(i + 1, vector<int>(j, -1));

    int mini = INT_MAX;
    for (int k = 0; k < j; k++)
    {
        mini = min(mini, solve2(i, k, triangle, dp));
    }

    return mini;
}

// TOP TO DOWN RECURSION   (0,0) to (i,j);

int solve3(int i, int j, vector<vector<int>> &triangle)
{

    if (i == triangle.size() - 1)
        return triangle[i][j];

    int down = triangle[i][j] + solve3(i + 1, j, triangle);
    int diagonal = triangle[i][j] + solve3(i + 1, j + 1, triangle);

    return min(down, diagonal);
}

int minimumTotal3(vector<vector<int>> &triangle)
{

    return solve3(0, 0, triangle);
}

// Memoization
int solve4(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp)
{

    if (i == triangle.size() - 1)
        return triangle[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int down = triangle[i][j] + solve4(i + 1, j, triangle, dp);
    int diagonal = triangle[i][j] + solve4(i + 1, j + 1, triangle, dp);

    dp[i][j] = min(down, diagonal);
    return dp[i][j];
}

int minimumTotal4(vector<vector<int>> &triangle)
{

    vector<vector<int>> dp(triangle.size(), vector<int>(triangle[triangle.size() - 1].size(), -1));
    return solve4(0, 0, triangle, dp);

} // Tabulation
int solve5(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp)
{
    int n = triangle.size();
    for (int k = 0; k < n; k++)
        dp[n - 1][k] = triangle[n - 1][k];

    for (int row = n - 2; row >= 0; row--)
    {
        for (int col = row; col >= 0; col--)
        {
            int down = triangle[row][col] + dp[row + 1][col];
            int diagonal = triangle[row][col] + dp[row + 1][col + 1];

            dp[row][col] = min(down, diagonal);
        }
    }

    return dp[0][0];
}

int minimumTotal5(vector<vector<int>> &triangle)
{

    vector<vector<int>> dp(triangle.size(), vector<int>(triangle[triangle.size() - 1].size(), -1));
    return solve5(0, 0, triangle, dp);
}

// spaceoptimization
int minimumTotal6(vector<vector<int>> &triangle)
{

    int n = triangle.size();
    vector<int> nextRow(n, 0), curr(n, 0);
    for (int k = 0; k < n; k++)
        nextRow[k] = triangle[n - 1][k];

    for (int row = n - 2; row >= 0; row--)
    {
        for (int col = row; col >= 0; col--)
        {
            int down = triangle[row][col] + nextRow[col];
            int diagonal = triangle[row][col] + nextRow[col + 1];

            curr[col] = min(down, diagonal);
        }

        nextRow = curr;
    }

    return nextRow[0];
}

int main()
{

    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << minimumTotal(triangle) << endl;
    cout << minimumTotal2(triangle) << endl;
    cout << minimumTotal3(triangle) << endl;
    cout << minimumTotal4(triangle) << endl;
    cout << minimumTotal5(triangle) << endl;
    cout << minimumTotal6(triangle) << endl;

    return 0;
}