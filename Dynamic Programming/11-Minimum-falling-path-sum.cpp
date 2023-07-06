// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

//     A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or  diagonally left / right.Specifically,the next element from position(row, col) will be(row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<vector<int>> &matrix)
{
    if (j < 0 || j >= matrix.size())
    {
        return 1e9;
    }
    if (i == 0)
        return matrix[i][j];

    int up = matrix[i][j] + solve(i - 1, j, matrix);

    int dRight = matrix[i][j] + solve(i - 1, j + 1, matrix);
    int dLeft = matrix[i][j] + solve(i - 1, j - 1, matrix);

    return min(up, min(dRight, dLeft));
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int i = matrix.size() - 1;

    int mini = 1e9;
    for (int j = 0; j <= i; j++)
    {
        mini = min(mini, solve(i, j, matrix));
    }

    return mini;
}

// Memoization
int solve2(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (j < 0 || j >= matrix.size())
    {
        return 1e9;
    }
    if (i == 0)
        return matrix[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];
    int up = matrix[i][j] + solve2(i - 1, j, matrix, dp);

    int dRight = matrix[i][j] + solve2(i - 1, j + 1, matrix, dp);
    int dLeft = matrix[i][j] + solve2(i - 1, j - 1, matrix, dp);

    dp[i][j] = min(up, min(dRight, dLeft));
    return dp[i][j];
}

int minFallingPathSum2(vector<vector<int>> &matrix)
{
    int i = matrix.size() - 1;
    vector<vector<int>> dp(i + 1, vector<int>(i + 1, -1));

    int mini = 1e9;
    for (int j = 0; j <= i; j++)
    {
        mini = min(mini, solve2(i, j, matrix, dp));
    }

    return mini;
}

// Tabulation

int solve3(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{

    for (int k = 0; k <= i; k++)
    {
        dp[0][k] = matrix[0][k];
    }

    for (int row = 1; row <= i; row++)
    {

        for (int col = 0; col <= j; col++)
        {

            int up = dp[row - 1][col];
            int dRight, dLeft;
            if (col + 1 < matrix.size())
            {
                dRight = dp[row - 1][col + 1];
            }
            else
            {
                dRight = 1e9;
            }

            if (col - 1 >= 0)
            {
                dLeft = dp[row - 1][col - 1];
            }
            else
            {
                dLeft = 1e9;
            }

            dp[row][col] = min(up, min(dLeft, dRight));

            if (dp[row][col] != 1e9)
            {
                dp[row][col] += matrix[row][col];
            }
        }
    }

    int mini = 1e9;
    for (int col = 0; col <= i; col++)
    {

        mini = min(mini, dp[i][col]);
    }

    return mini;
}

int minFallingPathSum3(vector<vector<int>> &matrix)
{
    int i = matrix.size() - 1;
    vector<vector<int>> dp(i + 1, vector<int>(i + 1, -1));

    return solve3(i, i, matrix, dp);
}

// Space Optimization

int solve4(int i, int j, vector<vector<int>> &matrix)
{   


    vector<int>prevRow(i+1);
    for (int k = 0; k <= i; k++)
    {
        prevRow[k] = matrix[0][k];
    }

    for (int row = 1; row <= i; row++)
    {   
        vector<int>curr(i+1,0);

        for (int col = 0; col <= j; col++)
        {

            int up = prevRow[col];
            int dRight, dLeft;
            if (col + 1 < matrix.size())
            {
                dRight =prevRow[col + 1];
            }
            else
            {
                dRight = 1e9;
            }

            if (col - 1 >= 0)
            {
                dLeft = prevRow[col - 1];
            }
            else
            {
                dLeft = 1e9;
            }

            curr[col] = min(up, min(dLeft, dRight));

            if (curr[col] != 1e9)
            {
                curr[col] += matrix[row][col];
            }
        }
        prevRow=curr;
    }

    int mini = 1e9;
    for (int col = 0; col <= i; col++)
    {

        mini = min(mini, prevRow[col]);
    }

    return mini;
}

int minFallingPathSum4(vector<vector<int>> &matrix)
{
    int i = matrix.size() - 1;
   

    return solve4(i, i, matrix);
}
int main()
{
    vector<vector<int>> matrix = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};

    cout << minFallingPathSum(matrix) << endl;
    cout << minFallingPathSum2(matrix) << endl;
    cout << minFallingPathSum3(matrix) << endl;
    cout << minFallingPathSum4(matrix) << endl;

    return 0;
}