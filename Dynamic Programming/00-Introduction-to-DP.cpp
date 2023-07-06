
// Two Approaches : - 1) Top Down => Recursion + Memoization
//                     2) Bottom Up => Tabulation

// How to  recogonize a DP question :=
// 1) Choice
// 2) Overlapping Problem (Usually in Recursive Function with 2 or more recursive call)
// 3) Optimal (Minimum , Maximum , Largest)

#include <bits/stdc++.h>
using namespace std;

// Top Down Approach

int fib_TD(int n, vector<int> &dp)
{
    // Time : O(n)
    // Space = O(n)

    // Step 1
    if (n == 0 || n == 1)
        return n;

    // Step 3

    if (dp[n] != -1)
    {
        return dp[n];
    }

    // Step 2

    dp[n] = fib_TD(n - 1, dp) + fib_TD(n - 2, dp);
    return dp[n];
}

// Bottom Down Approach
int fib_BU(int n, vector<int> &dp)
{

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i < n + 1; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// space optimization

int fib_SO(int n)
{

    int prev2 = 0;
    int prev1 = 1;

    int curr = 0;
    for (int i = 2; i < n + 1; i++)
    {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}

int main()
{

    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);

    // cout << fib_TD(n, dp);
    // cout << fib_BU(n, dp);
    cout << fib_SO(n);

    return 0;
}