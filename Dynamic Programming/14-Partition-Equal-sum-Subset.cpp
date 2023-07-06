#include <bits/stdc++.h>
using namespace std;

bool solve(int n, int sum, vector<int> &nums)
{

    if (sum == 0)
        return true;

    if (n == 0)
        return (nums[0] == sum);

    bool notTaken = solve(n - 1, sum, nums);

    bool taken = false;

    if (nums[n] <= sum)
    {

        taken = solve(n - 1, sum - nums[n], nums);
    }

    return notTaken || taken;
}

bool canPartition(vector<int> &nums)
{
    int sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }

    if (sum & 1)
    {
        return false;
    }

    sum = sum / 2;

    return solve(nums.size(), sum, nums);
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
    bool notTaken = solve2(arr, n - 1, sum, dp);

    bool taken = false;

    if (arr[n] <= sum)
    {

        taken = solve2(arr, n - 1, sum - arr[n], dp);
    }

    return dp[n][sum] = notTaken || taken;
}

bool canPartition2(vector<int> &nums)
{

    int sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }

    if (sum & 1)
    {
        return false;
    }

    sum = sum / 2;

    vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, -1));

    return solve2(nums, nums.size() - 1, sum, dp);
}
// Tabulation

bool canPartition3(vector<int> &arr)
{
    int sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }

    if (sum & 1)
    {
        return false;
    }

    sum = sum / 2;
    // equal to i
    int N = arr.size();
    vector<vector<bool>> dp(N, vector<bool>(sum + 1, 0));
    // If sum is 0, then answer is true
    for (int i = 0; i < N; i++)
        dp[i][0] = true;

    if (arr[0] <= sum)
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

bool canPartition4(vector<int> arr)
{
    int sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }

    if (sum & 1)
    {
        return false;
    }

    sum = sum / 2;
    int N = arr.size();
    vector<bool> prevRow(sum + 1, false), curr(sum + 1, 0);
    if (arr[0] <= sum)
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

    vector<int> arr = {1, 5, 11, 5};

    cout << canPartition(arr) << endl;
    cout << canPartition2(arr) << endl;
    cout << canPartition3(arr) << endl;
    cout << canPartition4(arr) << endl;

    return 0;
}