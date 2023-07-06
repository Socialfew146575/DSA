#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> coins, int amount)
{

    if (n == 0)
    {

        if (amount % coins[0] == 0)
            return 1;
        return 0;
    }

    int notTaken = solve(n - 1, coins, amount);
    int taken = 0;

    if (coins[n] <= amount)
        taken = solve(n, coins, amount - coins[n]);

    return notTaken + taken;
}

int change(int amount, vector<int> &coins)
{

    int n = coins.size();

    return solve(n - 1, coins, amount);
}

int solve2(int n, vector<int> coins, int amount, vector<vector<int>> &dp)
{

    if (n == 0)
    {

        if (amount % coins[0] == 0)
            return 1;
        return 0;
    }

    if (dp[n][amount] != -1)
        return dp[n][amount];

    int notTaken = solve2(n - 1, coins, amount, dp);
    int taken = 0;

    if (coins[n] <= amount)
        taken = solve2(n, coins, amount - coins[n], dp);

    return dp[n][amount] = notTaken + taken;
}

int change2(int amount, vector<int> &coins)
{

    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    return solve2(n - 1, coins, amount, dp);
}

int change3(int amount, vector<int> &coins)
{

    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    for (int i = 0; i <= amount; i++)
    {

        if (i % coins[0] == 0)
            dp[0][i] = 1;
        else
            dp[0][i] = 0;
    }

    for (int i = 1; i < n; i++)
    {

        for (int j = 0; j <= amount; j++)
        {

            int notTaken = dp[i - 1][j];
            int taken = 0;

            if (coins[i] <= j)
                taken = dp[i][j - coins[i]];

            dp[i][j] = notTaken + taken;
        }
    }

    return dp[n - 1][amount];
}
int change4(int amount, vector<int> &coins)
{

    int n = coins.size();
    vector<int> prev(amount + 1, 0), curr(amount + 1);

    for (int i = 0; i <= amount; i++)
    {

        if (i % coins[0] == 0)
            prev[i] = 1;
        else
            prev[i] = 0;
    }

    for (int i = 1; i < n; i++)
    {

        for (int j = 0; j <= amount; j++)
        {

            int notTaken = prev[j];
            int taken = 0;

            if (coins[i] <= j)
                taken = curr[j - coins[i]];

            curr[j] = notTaken + taken;
        }
        prev = curr;
    }

    return prev[amount];
}
int main()
{
    int amount = 5;
    vector<int> coins = {1, 2, 5};

    cout << change(amount, coins) << endl;
    cout << change2(amount, coins) << endl;
    cout << change3(amount, coins) << endl;
    cout << change4(amount, coins) << endl;
    return 0;
}