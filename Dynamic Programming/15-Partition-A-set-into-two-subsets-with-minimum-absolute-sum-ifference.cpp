//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr, int n, int sum, int totalSum)
{

    if (n == 0)
    {

        return abs((totalSum - sum) - sum);
    }

    int notTaken = solve(arr, n - 1, sum, totalSum);
    int Taken = solve(arr, n - 1, sum + arr[n - 1], totalSum);

    return min(notTaken, Taken);
}

int minDifference2(vector<int> arr)
{

    int sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }

    return solve(arr, arr.size(), 0, sum);
}
int solve3(vector<int> arr, int n, int sum, int totalSum, vector<vector<int>> &dp)
{

    if (n == 0)
    {

        return abs((totalSum - sum) - sum);
    }

    if (dp[n][sum] != -1)
        return dp[n][sum];

    int notTaken = solve3(arr, n - 1, sum, totalSum, dp);
    int Taken = solve3(arr, n - 1, sum + arr[n - 1], totalSum, dp);

    return dp[n][sum] = min(notTaken, Taken);
}

int minDifference3(vector<int> arr)
{

    int sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }

    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

    return solve3(arr, n, 0, sum, dp);
}

int minDifference(vector<int> arr, int n)
{
    // Your code goes here

    int totSum = 0;

    for (int i = 0; i < n; i++)
    {
        totSum += arr[i];
    }

    vector<vector<int>> dp(n, vector<int>(totSum + 1, -1));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    if (arr[0] <= totSum)
        dp[0][arr[0]] = true;

    // Fill the dp table in bottom up manner
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= totSum; j++)
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

    int mini = 1e9;

    for (int s1 = 0; s1 <= totSum / 2; s1++)
    {

        if (dp[n - 1][s1])
        {
            mini = min(mini, abs((totSum - s1) - s1));
        }
    }
    return mini;
}
int minDifference4(vector<int> arr, int n)
{
    // Your code goes here

    int totSum = 0;

    for (int i = 0; i < n; i++)
    {
        totSum += arr[i];
    }

   vector<bool>prevRow(totSum+1,false),curr(totSum+1);
    for (int i = 0; i < n; i++)
        prevRow[0] = true;

    if (arr[0] <= totSum)
       prevRow[arr[0]] = true;

    // Fill the dp table in bottom up manner
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= totSum; j++)
        {
            bool notTaken = prevRow[j];
            bool taken = false;

            if (arr[i] <= j)
            {
                taken = prevRow[j - arr[i]];
            }

           curr[j] = taken | notTaken;
        }

        prevRow=curr;
    }

    int mini = 1e9;

    for (int s1 = 0; s1 <= totSum / 2; s1++)
    {

        if (prevRow[s1])
        {
            mini = min(mini, abs((totSum - s1) - s1));
        }
    }
    return mini;
}

//{ Driver Code Starts.
int main()
{
    vector<int> arr = {1, 6, 11, 5};
    cout << minDifference(arr, 4) << endl;
    cout << minDifference2(arr) << endl;
    cout << minDifference3(arr) << endl;
    cout << minDifference4(arr,4) << endl;


    return 0;
}
// } Driver Code Ends