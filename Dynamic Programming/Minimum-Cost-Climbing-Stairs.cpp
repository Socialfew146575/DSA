#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(int n, vector<int> &cost)
{

    // BASECASE
    if (n == 0)
        return cost[0];

    if (n == 1)
        return cost[1];

    int ans = cost[n] + min(solve(n - 1, cost), solve(n - 2, cost));
    return ans;
}

int minCostClimbingStairs(vector<int> &cost)
{

    int n = cost.size();

    return min(solve(n - 1, cost), solve(n - 2, cost));
}

// DP

// Memoization
int solveDP(int n, vector<int> &cost, vector<int> &dp)
{

    // BASECASE
    if (n == 0)
        return cost[0];

    if (n == 1)
        return cost[1];

    if (dp[n] != -1)
        return dp[n];

    dp[n] = min(solveDP(n - 1, cost, dp), solveDP(n - 2, cost, dp)) + cost[n];
    return dp[n];
}

int minCostClimbingStairsDP(vector<int> &cost)
{

    int n = cost.size();
    vector<int> dp(n + 1, -1);
    return min(solveDP(n - 1, cost, dp), solveDP(n - 2, cost, dp));
}

// Tabulation

int minCostClimbingStairsDP2(vector<int> &cost)
{
    int n = cost.size();

    vector<int> dp(n + 1, -1);

    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < n; i++)
    {
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }

    return min(dp[n - 1], dp[n - 2]);
}


// Space Optimization

int minCostClimbingStairsDPSO(vector<int> &cost)
{
    int n = cost.size();

    int prev2=cost[0];
    int prev1=cost[1];

    int curr=0;
    for (int i = 2; i < n; i++)
    {
            curr=min(prev1,prev2)+cost[i];
            prev2=prev1;
            prev1=curr;
    }

    return min(prev1,prev2);
}
int main()
{
    vector<int> cost = {16, 19, 10, 12, 18};

    cout << minCostClimbingStairs(cost) << endl;
    cout << minCostClimbingStairsDP(cost) << endl;
    cout << minCostClimbingStairsDP2(cost) << endl;
    cout << minCostClimbingStairsDPSO(cost) << endl;

    return 0;
}