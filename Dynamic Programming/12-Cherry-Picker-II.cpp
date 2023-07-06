

// You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

// You have two robots that can collect cherries for you:

// Robot #1 is located at the top-left corner (0, 0), and
// Robot #2 is located at the top-right corner (0, cols - 1).
// Return the maximum number of cherries collection using both robots by following the rules below:

// From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
// When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
// When both robots stay in the same cell, only one takes the cherries.
// Both robots cannot move outside of the grid at any moment.
// Both robots should reach the bottom row in grid.

#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j1, int j2, vector<vector<int>> &grid)
{

    if (j1 < 0 || j1 >= grid[0].size())
        return -1e8;

    if (j2 < 0 || j2 >= grid[0].size())
        return -1e8;

    if (i == grid.size() - 1)
    {

        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }

    int maxi = -1;
    for (int row = -1; row <= 1; row++)
    {

        for (int col = -1; col <= 1; col++)
        {

            if (j1 == j2)
            {
                maxi = max(maxi, grid[i][j1] + solve(i + 1, j1 + row, j2 + col, grid));
            }
            else
            {
                maxi = maxi = max(maxi, grid[i][j2] + grid[i][j1] + solve(i + 1, j1 + row, j2 + col, grid));
            }
        }
    }

    return maxi;
}

int cherryPickup(vector<vector<int>> &grid)
{

    return solve(0, 0, grid[0].size() - 1, grid);
}

// Memoization

int solve2(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{

    if (j1 < 0 || j1 >= grid[0].size())
        return -1e8;

    if (j2 < 0 || j2 >= grid[0].size())
        return -1e8;

    if (i == grid.size() - 1)
    {

        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    int maxi = -1;
    for (int row = -1; row <= 1; row++)
    {

        for (int col = -1; col <= 1; col++)
        {

            if (j1 == j2)
            {
                maxi = max(maxi, grid[i][j1] + solve2(i + 1, j1 + row, j2 + col, grid, dp));
            }
            else
            {
                maxi = max(maxi, grid[i][j2] + grid[i][j1] + solve2(i + 1, j1 + row, j2 + col, grid, dp));
            }
        }
    }

    dp[i][j1][j2] = maxi;
    return dp[i][j1][j2];
}

int cherryPickup2(vector<vector<int>> &grid)
{

    vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));

    return solve2(0, 0, grid[0].size() - 1, grid, dp);
}

// Tabulation

int cherryPickup3(vector<vector<int>> &grid)
{

    vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));

    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < m; j++)
        {

            if (i == j)
                dp[n - 1][i][j] = grid[n - 1][i];
            else
                dp[n - 1][i][j] = grid[n - 1][i] + grid[n - 1][j];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {

        for (int j1 = 0; j1 < m; j1++)
        {

            for (int j2 = 0; j2 < m; j2++)
            {

                int maxi = -1e8;
                for (int row = -1; row <= 1; row++)
                {

                    for (int col = -1; col <= 1; col++)
                    {
                        int value = 0;
                        if (j1 == j2)
                        {
                            value = grid[i][j1];
                        }
                        else
                        {
                            value = grid[i][j1] + grid[i][j2];
                        }

                        if (j1 + row >= 0 && j1 + row < m && j2 + col >= 0 && j2 + col < m)
                            value += dp[i + 1][j1 + row][j2 + col];
                        else
                            value += -1e8;
                        maxi = max(maxi, value);
                    }
                }

                dp[i][j1][j2] = maxi;
            }
        }
    }

    return dp[0][0][m - 1];
}

// Space Optimization

int cherryPickup4(vector<vector<int>> &grid)
{

    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> prevRow(m, vector<int>(m, 0));

    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < m; j++)
        {

            if (i == j)
                prevRow[i][j] = grid[n - 1][i];
            else
                prevRow[i][j] = grid[n - 1][i] + grid[n - 1][j];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        vector<vector<int>> curr(m, vector<int>(m, 0));
        for (int j1 = 0; j1 < m; j1++)
        {

            for (int j2 = 0; j2 < m; j2++)
            {

                int maxi = -1e8;
                for (int row = -1; row <= 1; row++)
                {

                    for (int col = -1; col <= 1; col++)
                    {
                        int value = 0;
                        if (j1 == j2)
                        {
                            value = grid[i][j1];
                        }
                        else
                        {
                            value = grid[i][j1] + grid[i][j2];
                        }

                        if (j1 + row >= 0 && j1 + row < m && j2 + col >= 0 && j2 + col < m)
                            value += prevRow[j1 + row][j2 + col];
                        else
                            value += -1e8;
                        maxi = max(maxi, value);
                    }
                }

                curr[j1][j2] = maxi;
            }
        }
        prevRow = curr;
    }

    return prevRow[0][m - 1];
}

int main()
{

    vector<vector<int>> grid = {{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}};

    cout << cherryPickup(grid) << endl;
    cout << cherryPickup2(grid) << endl;
    cout << cherryPickup3(grid) << endl;
    cout << cherryPickup4(grid) << endl;

    return 0;
}