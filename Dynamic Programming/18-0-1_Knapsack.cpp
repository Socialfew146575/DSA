
#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(int n, vector<int> wt, vector<int> val, int C)
{

    if (n == 0)
    {
        if (wt[0] <= C)
        {
            return val[0];
        }
        return 0;
    }

    int notTaken = solve(n - 1, wt, val, C);
    int taken = INT_MIN;

    if (wt[n] <= C)
        taken = val[n] + solve(n - 1, wt, val, C - wt[n]);

    return max(notTaken, taken);
}

int knapsack(vector<int> wt, vector<int> val, int C)
{

    int n = wt.size() - 1;

    return solve(n, wt, val, C);
}
// Memoization
int solve2(int n, vector<int> wt, vector<int> val, int C,
           vector<vector<int>> &dp)
{

    if (n == 0)
    {
        if (wt[0] <= C)
        {
            return val[0];
        }
        return 0;
    }

    if (dp[n][C] != -1)
        return dp[n][C];

    int notTaken = solve2(n - 1, wt, val, C, dp);
    int taken = INT_MIN;

    if (wt[n] <= C)
        taken = val[n] + solve2(n - 1, wt, val, C - wt[n], dp);

    return dp[n][C] = max(notTaken, taken);
}

int knapsack2(vector<int> wt, vector<int> val, int C)
{

    int n = wt.size() - 1;

    vector<vector<int>> dp(n + 1, vector<int>(C + 1, -1));
    return solve2(n, wt, val, C, dp);
}

// Tabulation
int knapsack3(vector<int> wt, vector<int> val, int C)
{

    int n = wt.size();

    vector<vector<int>> dp(n, vector<int>(C + 1, 0));

    for (int i = wt[0]; i <= C; i++)
    {
        dp[0][i] = val[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= C; j++)
        {
            int notTaken = dp[i - 1][j];
            int taken = INT_MIN;

            if (wt[i] <= j)
                taken = val[i] + dp[i - 1][j - wt[i]];

            dp[i][j] = max(notTaken, taken);
        }
    }

    return dp[n - 1][C];
} // SO
int knapsack4(vector<int> wt, vector<int> val, int C)
{

    int n = wt.size();

    vector<int> prev(C + 1, 0), curr(C + 1);

    for (int i = wt[0]; i <= C; i++)
    {
        prev[i] = val[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= C; j++)
        {
            int notTaken = prev[j];
            int taken = INT_MIN;

            if (wt[i] <= j)
                taken = val[i] + prev[j - wt[i]];

            curr[j] = max(notTaken, taken);
        }
        prev = curr;
    }

    return prev[C];
} 



// Further SO
int knapsack5(vector<int> wt, vector<int> val, int C)
{

    int n = wt.size();

    vector<int> prev(C + 1, 0);

    for (int i = wt[0]; i <= C; i++)
    {
        prev[i] = val[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = C; j >= 0; j--)
        {
            int notTaken = prev[j];
            int taken = INT_MIN;

            if (wt[i] <= j)
                taken = val[i] + prev[j - wt[i]];

            prev[j] = max(notTaken, taken);
        }
       
    }

    return prev[C];
}
int main()
{

    vector<int> wt = {3, 2, 5};
    vector<int> value = {30, 40, 60};
    int C = 6;

    cout << knapsack(wt, value, C) << endl;
    cout << knapsack2(wt, value, C) << endl;
    cout << knapsack3(wt, value, C) << endl;
    cout << knapsack4(wt, value, C) << endl;
    cout << knapsack5(wt, value, C) << endl;

    return 0;
}