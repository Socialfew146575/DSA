#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(int ind, vector<int> heights, int k)
{

    if (ind == 0)
        return 0;

    int min_steps = 1e9;

    for (int i = 1; i < k + 1; i++)
    {

        if (ind - i >= 0)
        {
            int jump = solve(ind - i, heights, k) + abs(heights[ind] - heights[ind - i]);

            min_steps = min(min_steps, jump);
        }
    }

    return min_steps;
}

int frogJump(int n, vector<int> &heights, int k)
{

    return solve(n - 1, heights, k);
}

// Memoization
int solve2(int ind, vector<int> heights, vector<int> &dp, int k)
{

    if (ind == 0)
        return 0;

    if (dp[ind] != -1)
        return dp[ind];

    int min_steps = 1e9;

    for (int i = 1; i < k + 1; i++)
    {

        if (ind - i >= 0)
        {
            int jump = solve(ind - i, heights, k) + abs(heights[ind] - heights[ind - i]);

            min_steps = min(min_steps, jump);
        }

        dp[ind] = min_steps;
    }
    return dp[ind];
}

int frogJump2(int n, vector<int> &heights, int k)
{

    vector<int> dp(n, -1);

    return solve2(n - 1, heights, dp, k);
}

// Tabulation

int frogJump3(int n, vector<int> heights, int k)
{
    vector<int> dp(n, -1);

    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int min_steps = INT_MAX;

        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int jump = dp[i - j] + abs(heights[i] - heights[i - j]);

                min_steps = min(min_steps, jump);
            }
        }

        dp[i] = min_steps;
    }

    return dp[n - 1];
}

int main()
{

    vector<int> heights = {10, 20, 30, 10};
    cout << frogJump(4, heights, 3) << endl;
    cout << frogJump2(4, heights, 3) << endl;
    cout << frogJump3(4, heights, 3) << endl;

    return 0;
}