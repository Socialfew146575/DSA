//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>arr, int n, int sum, vector<vector<int>> &dp)
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

    return dp[n][sum] = notTaken + taken;
}

int perfectSum(vector<int>arr, int n, int sum)
{
    // Your code goes here
    // int count=0;

    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return solve(arr, n - 1, sum, dp);
}
int solve2(vector<int>arr, int n, int sum)
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

  

    int notTaken = solve2(arr, n - 1, sum);

    int taken = 0;

    if (arr[n] <= sum)
        taken = solve2(arr, n - 1, sum - arr[n]);

    return  notTaken + taken;
}

int perfectSum2(vector<int> arr, int n, int sum)
{
    // Your code goes here
    // int count=0;

   
    return solve2(arr, n - 1, sum);
}
int perfectSum3(vector<int> arr, int n, int sum)
{
    // Your code goes here
    // int count=0;

    // Write your code here.
 

    // Your code goes here

    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    if (arr[0] <= sum)
        dp[0][arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {

            int notTaken = dp[i - 1][j];
            int taken = 0;
            if (arr[i] <= j)
                taken = dp[i - 1][j - arr[i]];

            dp[i][j] = (taken + notTaken) ;
        }
    }

    return dp[n - 1][sum];
}int perfectSum4(vector<int> arr, int n, int sum)
{
    // Your code goes here
    // int count=0;

    // Write your code here.
 

    // Your code goes here

   vector<int>prevRow(sum+1,0),curr(sum+1,0);

    for (int i = 0; i < n; i++)
    {
       prevRow[0] = 1;
    }

    if (arr[0] <= sum)
        prevRow[arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {

            int notTaken = prevRow[j];
            int taken = 0;
            if (arr[i] <= j)
                taken = prevRow[j - arr[i]];

            curr[j] = (taken + notTaken) ;
        }
        prevRow=curr;
    }

    return prevRow[sum];
}

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        cout << perfectSum(a, n, sum) << "\n";
        cout << perfectSum2(a, n, sum) << "\n";
        cout << perfectSum3(a, n, sum) << "\n";
        cout << perfectSum4(a, n, sum) << "\n";
    }
    return 0;
}

// } Driver Code Ends