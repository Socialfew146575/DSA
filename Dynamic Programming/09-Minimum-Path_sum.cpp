// Given a m x n grid filled with non - negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note : You can only move either down or right at any point in time.

#include <bits/stdc++.h>
using namespace std;

// Recursion

int solve(int i, int j, vector<vector<int>> &grid)
{

    if (i == 0 && j == 0)
        return grid[0][0];

    if (i < 0 || j < 0)
        return 1e9;

    int up = solve(i - 1, j, grid) + grid[i][j];
    int left = solve(i, j - 1, grid) + grid[i][j];

    return min(up, left);
}

int minPathSum(vector<vector<int>> &grid)
{

    int i = grid.size() - 1;
    int j = grid[0].size() - 1;

    return solve(i, j, grid);
}

// Memoization

int solve2(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{

    if (i == 0 && j == 0)
        return grid[0][0];

    if (i < 0 || j < 0)
        return 1e9;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = solve2(i - 1, j, grid, dp) + grid[i][j];
    int left = solve2(i, j - 1, grid, dp) + grid[i][j];

    dp[i][j] = min(up, left);
    return dp[i][j];
}

int minPathSum2(vector<vector<int>> &grid)
{

    int i = grid.size() - 1;
    int j = grid[0].size() - 1;
    if (i == 0 && j == 0)
        return grid[0][0];
    vector<vector<int>> dp(i + 1, vector<int>(j + 1, -1));
    return solve2(i, j, grid, dp);
}

// Tabulation

int solve3(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{

    for (int row = 0; row <= i; row++)
    {
        for (int col = 0; col <= j; col++)
        {
            int up = INT_MAX;
            int left = INT_MAX;
            if (row == 0 && col == 0)
                dp[0][0] = grid[0][0];
            else
            {

                if (row > 0)
                    up = dp[row - 1][col] + grid[row][col];
                if (col > 0)
                    left = dp[row][col - 1] + grid[row][col];

                dp[row][col] = min(up, left);
            }
        }
    }

    return dp[i][j];
}

int minPathSum3(vector<vector<int>> &grid)
{

    int i = grid.size() - 1;
    int j = grid[0].size() - 1;
    if (i == 0 && j == 0)
        return grid[0][0];
    vector<vector<int>> dp(i + 1, vector<int>(j + 1, -1));
    return solve3(i, j, grid, dp);
}

// Space Optimization
int solve4(int i, int j, vector<vector<int>> &grid)
{

    vector<int> prevRow(j + 1, 0);

    for (int row = 0; row <= i; row++)
    {
        vector<int> curr(j + 1, 0);

        for (int col = 0; col <= j; col++)
        {

            if (row == 0 && col == 0)
                curr[0] = grid[0][0];
            else
            {

                int up = grid[row][col];

                if (row > 0)
                    up += prevRow[col];
                else
                    up += 1e9;

                int left = grid[row][col];
                if (col > 0)
                    left += curr[col - 1];
                else
                    left += 1e9;

                curr[col] = min(up, left);
            }

        }
            prevRow = curr;
    }

    return prevRow[j];
}

int minPathSum4(vector<vector<int>> &grid)
{

    int i = grid.size() - 1;
    int j = grid[0].size() - 1;
    if (i == 0 && j == 0)
        return grid[0][0];

    return solve4(i, j, grid);
}

int main()
{

    vector<vector<int>> grid = {{1, 3, 1},
                                {1, 5, 1},
                                {4, 2, 1}};

    cout
        << minPathSum(grid) << endl;
    cout << minPathSum2(grid) << endl;
    cout << minPathSum3(grid) << endl;
    cout << minPathSum4(grid) << endl;

    return 0;
}