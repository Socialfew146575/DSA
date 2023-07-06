// Total Unique Paths

// There is a robot on an m x n grid.The robot is initially located at the top - left corner(i.e., grid[0][0]).The robot tries to move to the bottom - right corner(i.e., grid[m - 1][n - 1]).The robot can only move either down or right at any point in time.
//   Given the two integers m and n,
//     return the number of possible unique paths that the robot can take to reach the bottom - right corner.

#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(int i, int j)
{

    if (i == 0 && j == 0)
        return 1;

    if (j < 0 || i < 0)
        return 0;

    int up = solve(i - 1, j);
    int left = solve(i, j - 1);

    return up + left;
}

int uniquePaths(int m, int n)
{

    return solve(m - 1, n - 1);
}

// Memoization

int solve2(int i, int j, vector<vector<int>> &dp)
{

    if (i == 0 && j == 0)
        return 1;

    if (j < 0 || i < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = solve2(i - 1, j, dp);
    int left = solve2(i, j - 1, dp);

    dp[i][j] = up + left;
    return dp[i][j];
}

int uniquePaths2(int m, int n)
{

    vector<vector<int>> dp(m, vector<int>(n, -1));

    return solve2(m - 1, n - 1, dp);
}

// Tabulation

int solve3(int i, int j, vector<vector<int>> &dp)
{

    dp[0][0] = 1;

    for (int row = 0; row <= i; row++)
    {

        for (int col = 0; col <= j; col++)
        {
            int up = 0;
            int left = 0;
            if (row == 0 && col == 0)
                continue;

            if (row - 1 >= 0)
                up = dp[row - 1][col];
            if (col - 1 >= 0)
                left = dp[row][col - 1];

            dp[row][col] = up + left;
        }
    }

    return dp[i][j];
}

int uniquePaths3(int m, int n)
{

    vector<vector<int>> dp(m, vector<int>(n, -1));

    return solve3(m - 1, n - 1, dp);
}

// Space Optimization

// int solve4(int i, int j)
// {

//     vector<int> prevRow(j + 1, 0);

//     for (int row = 0; row <= i; row++)
//     {
//     int prevCol = 0;

//         for (int col = 0; col <= j; col++)
//         {
//             int curr = 0;
//             if (row == 0 && col == 0)
//                 curr = 1;

//             else
//             {
//                 curr=prevRow[col]+prevCol;

//             }

//             prevRow[col]=curr;
//             prevCol=curr;

//         }

//     }

//     return prevRow[j];
// }
int solve4(int i, int j)
{

    vector<int> prevRow(j + 1, 0);

    for (int row = 0; row <= i; row++)
    {
        vector<int> curr(j + 1, 0);

        for (int col = 0; col <= j; col++)
        {

            if (row == 0 && col == 0)
                curr[0] = 1;

            else
            {
                curr[col] = prevRow[col];

                if (col - 1 >= 0)
                {
                    curr[col] += curr[col - 1];
                }
            }
        }
        prevRow = curr;
    }

    return prevRow[j];
}

int uniquePaths4(int m, int n)
{

    return solve4(m - 1, n - 1);
}

int main()
{
    cout << uniquePaths(3, 7) << endl;
    cout << uniquePaths2(3, 7) << endl;
    cout << uniquePaths3(3, 7) << endl;
    cout << uniquePaths4(3, 7) << endl;

    return 0;
}