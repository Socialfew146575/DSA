#include <bits/stdc++.h>
using namespace std;

int m = (int)1e9 + 7;

int solve(vector<int> arr, int n, int sum)
{
    if (n == 0)
    {

        if (sum == 0 && arr[0] == sum)
            return 2;
        else if (arr[0] == sum || sum == 0)
            return 1;
        else
            return 0;
    }


    int notTaken = solve(arr, n - 1, sum);

    int taken = 0;

    if (arr[n] <= sum)
        taken = solve(arr, n - 1, sum - arr[n]);

    return (notTaken + taken) % m;
}

int perfectSum(vector<int> arr, int n, int sum)
{
    
    return solve(arr, n - 1, sum);
}

int countPartitions(int n, int d, vector<int> &arr)
{
    // Code here
    int sum = 0;
    for (auto i : arr)
    {
        sum += i;
    }

    if (sum - d < 0 || (sum - d) & 1)
        return false;

    // vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
    return perfectSum(arr, n, (sum - d) / 2);
}

int solve2(vector<int> arr, int n, int sum, vector<vector<int>> &dp)
{
    if (n == 0)
    {

        if (sum == 0 && arr[0] == sum)
            return 2;
        else if (arr[0] == sum || sum == 0)
            return 1;
        else
            return 0;
    }

    if (dp[n][sum] != -1)
        return dp[n][sum];

    int notTaken = solve2(arr, n - 1, sum, dp);

    int taken = 0;

    if (arr[n] <= sum)
        taken = solve2(arr, n - 1, sum - arr[n], dp);

    return dp[n][sum] = (notTaken + taken) % m;
}

int perfectSum2(vector<int> arr, int n, int sum)
{
    // Your code goes here
    // int count=0;

    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return solve2(arr, n - 1, sum, dp);
}

int countPartitions2(int n, int d, vector<int> &arr)
{
    // Code here
    int sum = 0;
    for (auto i : arr)
    {
        sum += i;
    }

    if (sum - d < 0 || (sum - d) & 1)
        return false;

    // vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
    return perfectSum2(arr, n, (sum - d) / 2);
}



int perfectSum3(vector<int> arr, int n, int sum)
{
    // Your code goes here
    // int count=0;

    // vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

    vector<int> prevRow(sum + 1, 0), curr(sum + 1);

    if (arr[0] == 0)
        prevRow[0] = 2;
    else
        prevRow[0] = 1;

    if (arr[0] != 0 && arr[0] <= sum)
        prevRow[arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {

            int notTaken = prevRow[j];
            int taken = 0;
            if (arr[i] <= j)
                taken = prevRow[j - arr[i]];

            curr[j] = (taken + notTaken) % m;
        }
        prevRow = curr;
    }

    return prevRow[sum];
}


int countPartitions3(int n, int d, vector<int> &arr)
{
    // Code here
    int sum = 0;
    for (auto i : arr)
    {
        sum += i;
    }

    if (sum - d < 0 || (sum - d) & 1)
        return false;

    // vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
    return perfectSum3(arr, n, (sum - d) / 2);
}

int solve(vector<int> arr, int n, int sum, vector<vector<int>> &dp)
{
    if (n == 0)
    {

        if (sum == 0 && arr[0] == sum)
            return 2;
        else if (arr[0] == sum || sum == 0)
            return 1;
        else
            return 0;
    }

    if (dp[n][sum] != -1)
        return dp[n][sum];

    int notTaken = solve(arr, n - 1, sum, dp);

    int taken = 0;

    if (arr[n] <= sum)
        taken = solve(arr, n - 1, sum - arr[n], dp);

    return dp[n][sum] = (notTaken + taken) % m;
}

int perfectSum4(vector<int> arr, int n, int sum)
{
    // Your code goes here
    // int count=0;

    // vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

    vector<int> prevRow(sum + 1, 0), curr(sum + 1);

    if (arr[0] == 0)
        prevRow[0] = 2;
    else
        prevRow[0] = 1;

    if (arr[0] != 0 && arr[0] <= sum)
        prevRow[arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {

            int notTaken = prevRow[j];
            int taken = 0;
            if (arr[i] <= j)
                taken = prevRow[j - arr[i]];

            curr[j] = (taken + notTaken) % m;
        }
        prevRow = curr;
    }

    return prevRow[sum];
}


int countPartitions4(int n, int d, vector<int> &arr)
{
    // Code here
    int sum = 0;
    for (auto i : arr)
    {
        sum += i;
    }

    if (sum - d < 0 || (sum - d) & 1)
        return false;

    // vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
    return perfectSum4(arr, n, (sum - d) / 2);
}

int main()
{   
    vector<int>arr={1,1,1,1};
    int d=0;

    cout<<countPartitions(4,d,arr)<<endl;
    cout<<countPartitions2(4,d,arr)<<endl;
    cout<<countPartitions3(4,d,arr)<<endl;
    cout<<countPartitions4(4,d,arr)<<endl;

    return 0;
}