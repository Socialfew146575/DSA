#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &coins, int n, int V)
{

    if (n == 0)
    {

        if (V % coins[0] == 0)
            return V / coins[0];

        return 1e9;
    }

    int notTaken = solve(coins, n - 1, V);
    int taken = 1e9;

    if (coins[n] <= V)
        taken = 1 + solve(coins, n, V - coins[n]);

    return min(taken, notTaken);
}

int coinChange(vector<int> &coins, int V)
{

    int n = coins.size();

    int ans = solve(coins, n - 1, V);

    if (ans == 1e9)
        return -1;
    else
        return ans;
}
int solve2(vector<int> &coins, int n, int V, vector<vector<int>> &dp)
{

    if (n == 0)
    {

        if (V % coins[0] == 0)
            return V / coins[0];

        return 1e9;
    }

    if (dp[n][V] != -1)
        return dp[n][V];

    int notTaken = solve2(coins, n - 1, V, dp);
    int taken = 1e9;

    if (coins[n] <= V)
        taken = 1 + solve2(coins, n, V - coins[n], dp);

    return dp[n][V] = min(taken, notTaken);
}

int coinChange2(vector<int> &coins, int V)
{

    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(V + 1, -1));
    int ans = solve2(coins, n - 1, V, dp);

    if (ans == 1e9)
        return -1;
    else
        return ans;
}
int coinChange3(vector<int> &coins, int V)
{

    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(V + 1, -1));

    for (int i = 0; i <= V; i++)
    {
        if (i % coins[0] == 0)
            dp[0][i] = i / coins[0];
        else
            dp[0][i] = 1e9;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < V + 1; j++)
        {
            int notTaken = dp[i - 1][j];
            int taken = 1e9;

            if (coins[i] <= j)
                taken = 1 + dp[i][j - coins[i]];
            dp[i][j] = min(taken, notTaken);
        }
    }

    if (dp[n - 1][V] == 1e9)
        return -1;
    else
        return dp[n - 1][V];
}
int coinChange4(vector<int> &coins, int V)
{

    int n = coins.size();
    vector<int> prev(V + 1, 0), curr(V + 1);

    for (int i = 0; i <= V; i++)
    {
        if (i % coins[0] == 0)
            prev[i] = i / coins[0];
        else
            prev[i] = 1e9;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < V + 1; j++)
        {
            int notTaken = prev[j];
            int taken = 1e9;

            if (coins[i] <= j)
                taken = 1 + curr[j - coins[i]];
            curr[j] = min(taken, notTaken);
        }
        prev = curr;
    }

    if (prev[V] == 1e9)
        return -1;
    else
        return prev[V];
}
int main()
{

    vector<int> coins = {1,
                         2,
                         5};
    int amount = 11;

    cout << coinChange(coins, amount) << endl;
    cout << coinChange2(coins, amount) << endl;
    cout << coinChange3(coins, amount) << endl;
    cout << coinChange4(coins, amount) << endl;

    return 0;
}