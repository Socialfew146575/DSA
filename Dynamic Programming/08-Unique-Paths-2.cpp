// MAZE OBSTACLES

// You are given an m x n integer array grid.There is a robot initially located at the top - left corner(i.e., grid[0][0]).The robot tries to move to the bottom - right corner(i.e., grid[m - 1][n - 1]).The robot can only move either down or right at any point in time.

//   An obstacle and space are marked as 1 or 0 respectively in grid.A path that the robot takes cannot include any square that is an obstacle.

//  Return the number of possible unique paths that the robot can take to reach the bottom- right corner.

#include <bits/stdc++.h>
using namespace std;

// Recursion

int solve(int i, int j, vector<vector<int>> &grid)
{

    if (i >= 0 && j >= 0 && grid[i][j] == 1)
        return 0;

    if (i == 0 && j == 0)
        return 1;

    if (i < 0 || j < 0)
        return 0;

    int up = solve(i - 1, j, grid);
    int left = solve(i, j - 1, grid);

    return up + left;
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{

    int i = obstacleGrid.size() - 1;
    int j = obstacleGrid[0].size() - 1;

    return solve(i, j, obstacleGrid);
}

// Memoization

int solve2(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i >= 0 && j >= 0 && grid[i][j] == 1)
        return 0;
    if (i == 0 && j == 0)
        return 1;

    if (j < 0 || i < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = solve2(i - 1, j, grid, dp);
    int left = solve2(i, j - 1, grid, dp);

    dp[i][j] = up + left;
    return dp[i][j];
}

int uniquePathsWithObstacles2(vector<vector<int>> &obstacleGrid)
{

    int i = obstacleGrid.size() - 1;
    int j = obstacleGrid[0].size() - 1;
    vector<vector<int>> dp(i + 1, vector<int>(j + 1, -1));

    return solve2(i, j, obstacleGrid, dp);
}

// Tabulation

int solve3(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{

    if (grid[0][0] == 1)
        dp[0][0] = 0;
    else

        dp[0][0] = 1;

    for (int row = 0; row <= i; row++)
    {

        for (int col = 0; col <= j; col++)
        {
            if (grid[row][col] == 1)
            {
                dp[row][col] = 0;
            }
            else
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
    }

    return dp[i][j];
}

int uniquePathsWithObstacles3(vector<vector<int>> &obstacleGrid)
{

    int i = obstacleGrid.size() - 1;
    int j = obstacleGrid[0].size() - 1;
    vector<vector<int>> dp(i + 1, vector<int>(j + 1, -1));

    return solve3(i, j, obstacleGrid, dp);
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
int solve4(int i, int j, vector<vector<int>> &grid)
{

    vector<int> prevRow(j + 1, 0);

    for (int row = 0; row <= i; row++)
    {
        vector<int> curr(j + 1, 0);

        for (int col = 0; col <= j; col++)
        {

            if (row == 0 && col == 0 && grid[0][0] != 1)
                curr[0] = 1;

            else if (row == 0 && col == 0 && grid[0][0] == 1)
                curr[0] = 1;
            else if (grid[row][col] == 1)
            {
                curr[col] = 0;
            }
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

int uniquePathsWithObstacles4(vector<vector<int>> &grid)
{

    return solve4(grid.size() - 1, grid[0].size() - 1, grid);
}

int main()
{
    vector<vector<int>> grid(3, vector<int>(3, 0));
    grid[1][1] = 1;

    cout << uniquePathsWithObstacles(grid) << endl;
    cout << uniquePathsWithObstacles2(grid) << endl;
    cout << uniquePathsWithObstacles3(grid) << endl;
    cout << uniquePathsWithObstacles4(grid) << endl;
    vector<vector<int>> grid2(2, vector<int>(2, 0));
    grid2[0][1] = 1;

    cout << uniquePathsWithObstacles(grid2) << endl;
    cout << uniquePathsWithObstacles2(grid2) << endl;
    cout << uniquePathsWithObstacles3(grid2) << endl;
    cout << uniquePathsWithObstacles4(grid2) << endl;

    return 0;
}