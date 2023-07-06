#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> arr, int n, int sum)
{

    if (sum == 0)
        return true;

    if (n == 0)
        return false;

    if (arr[n - 1] <= sum)
    {
        int taken = solve(arr, n - 1, sum - arr[n - 1]);
        int notTaken = solve(arr, n - 1, sum);

        return taken || notTaken;
    }

    else
    {

        return solve(arr, n - 1, sum);
    }
}

bool isSubsetSum(vector<int> arr, int sum)
{
    // code here

    return solve(arr, arr.size(), sum);
}

// Memoization
bool solve2(vector<int> arr, int n, int sum, vector<vector<int>> &dp)
{

    if (sum == 0)
        return true;

    if (n == 0)
        return false;

    if (dp[n][sum] != -1)
        return dp[n][sum];

    if (arr[n - 1] <= sum)
    {
        int taken = solve2(arr, n - 1, sum - arr[n - 1], dp);
        int notTaken = solve2(arr, n - 1, sum, dp);

        return dp[n][sum] = taken || notTaken;
    }

    else
    {

        return dp[n][sum] = solve2(arr, n - 1, sum, dp);
    }
}

bool isSubsetSum2(vector<int> arr, int sum)
{
    // code here

    vector<vector<int>> dp(arr.size() + 1, vector<int>(sum + 1, -1));
    return solve2(arr, arr.size(), sum, dp);
}

// Tabulation

bool isSubsetSum3(vector<int> arr, int sum)
{
    // The value of subset[i][j] will be true if
    // there is a subset of arr[0..j-1] with sum
    // equal to i
    int N = arr.size();
    vector<vector<bool>> subset(N + 1, vector<bool>(sum + 1));
    // If sum is 0, then answer is true
    for (int i = 0; i <= N; i++)
        subset[i][0] = true;

    // If sum is not 0 and set is empty,
    // then answer is false
    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;

    // Fill the subset table in bottom up manner
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < arr[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= arr[i - 1])
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - arr[i - 1]];
        }
    }

    return subset[N][sum];
}

int main()
{
    int N = 6;
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    cout<<isSubsetSum(arr,sum)<<endl; 
    cout<<isSubsetSum2(arr,sum)<<endl; 
    cout<<isSubsetSum3(arr,sum)<<endl; 
    return 0;
}