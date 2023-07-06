#include <bits/stdc++.h>
using namespace std;

// Recursion
// Count number of ways to climb stair n if we can only climb 1 or 2 stair at a time;

int countDistinctWayToClimbStair(long long n)
{
    if (n <= 1)
        return n;

    return countDistinctWayToClimbStair(n - 1) + countDistinctWayToClimbStair(n - 2);
}

// DP

// Top Down
int countDP(long long n, vector<long long> &dp)
{

    if (n <= 1)
        dp[n] = 1;

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = countDP(n - 1, dp) + countDP(n - 2, dp);
    return dp[n];
}

// Bottom Up

int countDP2(long long n, vector<long long> &dp2)
{

    dp2[0] = 1;
    dp2[1] = 1;

    for (int i = 2; i < n + 1; i++)
    {
        dp2[i] = dp2[i - 1] + dp2[i - 2];
    }

    return dp2[n];
}

int main()
{
    int stairs = 5;

    int ans = countDistinctWayToClimbStair(stairs + 1);
    cout << ans << endl;

    vector<long long> dp(stairs + 1, -1);

    cout << countDP(stairs, dp) << endl;

    vector<long long> dp2(stairs + 1, -1);
    cout << countDP2(stairs, dp2);

    return 0;
}