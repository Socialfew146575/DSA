#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(int ind, vector<int> heights)
{

    if (ind == 0)
        return 0;
    int left = solve(ind - 1, heights) + abs(heights[ind] - heights[ind - 1]);
    int right = 1e9;

    if (ind > 1)
        right = solve(ind - 2, heights) + abs(heights[ind] - heights[ind - 2]);

    return min(left, right);
}

int frogJump(int n, vector<int> &heights)
{

    return solve(n - 1, heights);
}

// Memoization
int solve2(int ind, vector<int> heights, vector<int> &dp)
{

    if (ind == 0)
        return 0;

    if (dp[ind] != -1)
        return dp[ind];
    int left = solve2(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);
    int right = 1e9;

    if (ind > 1)
        right = solve2(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);

    dp[ind] = min(left, right);
    return dp[ind];
}

int frogJump2(int n, vector<int> &heights)
{

    vector<int> dp(n, -1);

    return solve2(n - 1, heights, dp);
}

// Tabulation

int frogJump3(int n, vector<int> heights)
{
    vector<int> dp(n, -1);

    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int fs = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int ss = 1e9;

        if (i > 1)
        {
            ss = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        }
        dp[i] = min(fs, ss);
    }

    return dp[n - 1];
}

// SpaceOptimization
int frogJump4(int n, vector<int> heights)
{
   

    int prev2=0,prev1=0,curr=0;


    for (int i = 1; i < n; i++)
    {
        int fs = prev1 + abs(heights[i] - heights[i - 1]);
        int ss = 1e9;

        if (i > 1)
        {
            ss = prev2 + abs(heights[i] - heights[i - 2]);
        }
        curr = min(fs, ss);
        prev2=prev1;
        prev1=curr;
    }

    return prev1;
}
int main()
{

    vector<int> heights = {10, 20, 30, 10};
    cout << frogJump(4, heights) << endl;
    cout << frogJump2(4, heights) << endl;
    cout << frogJump3(4, heights) << endl;
    cout << frogJump4(4, heights) << endl;

    return 0;
}