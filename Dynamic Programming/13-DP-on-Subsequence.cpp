#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> arr, int n, int sum)
{

    if (sum == 0)
        return true;

    if (n == 0)
        return (arr[0] == sum);

    bool notTaken = solve(arr, n - 1, sum);

    bool taken = false;

    if (arr[n] <= sum)
    {

        taken = solve(arr, n - 1, sum - arr[n]);
    }

    return notTaken || taken;
}

bool isSubsetSum(vector<int> arr, int sum)
{
    // code here

    return solve(arr, arr.size() - 1, sum);
}

// Memoization
bool solve2(vector<int> arr, int n, int sum, vector<vector<int>> &dp)
{

    if (sum == 0)
        return true;

    if (n == 0)
        return (arr[0] == sum);

    if (dp[n][sum] != -1)
        return dp[n][sum];
    bool notTaken = solve2(arr, n - 1, sum,dp);

    bool taken = false;

    if (arr[n] <= sum)
    {

        taken = solve2(arr, n - 1, sum - arr[n],dp);
    }

    return dp[n][sum] = notTaken || taken;
}

bool isSubsetSum2(vector<int> arr, int sum)
{
    // code here

    vector<vector<int>> dp(arr.size(), vector<int>(sum + 1, -1));
    return solve2(arr, arr.size() - 1, sum, dp);
}

// Tabulation

bool isSubsetSum3(vector<int> arr, int sum)
{
    // The value of subset[i][j] will be true if
    // there is a subset of arr[0..j-1] with sum
    // equal to i
    int N = arr.size();
    vector<vector<bool>> dp(N, vector<bool>(sum + 1, 0));
    // If sum is 0, then answer is true
    for (int i = 0; i < N; i++)
        dp[i][0] = true;

    dp[0][arr[0]] = true;

    // Fill the dp table in bottom up manner
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            bool notTaken = dp[i - 1][j];
            bool taken = false;

            if (arr[i] <= j)
            {
                taken = dp[i - 1][j - arr[i]];
            }

            dp[i][j] = taken | notTaken;
        }
    }

    return dp[N - 1][sum];
}

// Space Optimization

bool isSubsetSum4(vector<int> arr, int sum)
{
    int N = arr.size();
    vector<bool> prevRow(sum + 1, false), curr(sum + 1, 0);
    prevRow[arr[0]] = true;
    prevRow[0] = curr[0] = true;
    // Fill the dp table in bottom up manner
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            bool notTaken = prevRow[j];
            bool taken = false;

            if (arr[i] <= j)
            {
                taken = prevRow[j - arr[i]];
            }

            curr[j] = taken | notTaken;
        }
        prevRow = curr;
        
    }

    return prevRow[sum];
}

int main()
{
    int N = 6;
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    cout << isSubsetSum(arr, sum) << endl;
    cout << isSubsetSum2(arr, sum) << endl;
    cout << isSubsetSum3(arr, sum) << endl;
    cout << isSubsetSum4(arr, sum) << endl;
    return 0;
}