//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

int solve(int n, int price[], int N)
{

    if (n == 0)
    {

        return N * price[0];
    }

    int notTaken = solve(n - 1, price, N);

    int taken = INT_MIN;

    int rodLength = n + 1;

    if (rodLength <= N)
        taken = price[n] + solve(n, price, N - rodLength);

    return max(taken, notTaken);
}

int cutRod(int price[], int n)
{

    return solve(n - 1, price, n);
}

int solve2(int n, int price[], int N, vector<vector<int>> dp)
{

    if (n == 0)
    {

        return N * price[0];
    }

    if (dp[n][N] != -1)
        return dp[n][N];

    int notTaken = solve2(n - 1, price, N, dp);

    int taken = INT_MIN;

    int rodLength = n + 1;

    if (rodLength <= N)
        taken = price[n] + solve2(n, price, N - rodLength, dp);

    return dp[n][N] = max(taken, notTaken);
}

int cutRod2(int price[], int n)
{
    // code here

    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solve2(n - 1, price, n, dp);
}

//{ Driver Code Starts.
int cutRod3(int price[], int n)
{
    // code here

    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    for (int i = 0; i <= n; i++)
    {

        dp[0][i] = i * price[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {

            int notTaken = dp[i - 1][j];

            int taken = INT_MIN;

            int rodLength = i + 1;

            if (rodLength <= j)
                taken = price[i] + dp[i][j - rodLength];

            dp[i][j] = max(taken, notTaken);
        }
    }

    return dp[n - 1][n];
}

int cutRod4(int price[], int n)
{
    // code here

    vector<int> prev(n + 1, 0), curr(n + 1, 0);

    for (int i = 0; i <= n; i++)
    {

        prev[i] = i * price[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {

            int notTaken = prev[j];

            int taken = INT_MIN;

            int rodLength = i + 1;

            if (rodLength <= j)
                taken = price[i] + curr[j - rodLength];

            curr[j] = max(taken, notTaken);
        }
        prev = curr;
    }

    return prev[n];
}

int cutRod5(int price[], int n)
{
    // code here

    vector<int> prev(n + 1, 0);

    for (int i = 0; i <= n; i++)
    {

        prev[i] = i * price[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {

            int notTaken = prev[j];

            int taken = INT_MIN;

            int rodLength = i + 1;

            if (rodLength <= j)
                taken = price[i] + prev[j - rodLength];

            prev[j] = max(taken, notTaken);
        }
    }

    return prev[n];
}
int main()
{
    int N = 8;
    int Price[] = {1, 5, 8, 9, 10, 17, 17, 20};

    cout << cutRod(Price, N) << endl;
    cout << cutRod2(Price, N) << endl;
    cout << cutRod3(Price, N) << endl;
    cout << cutRod4(Price, N) << endl;
    cout << cutRod5(Price, N) << endl;
    return 0;
}
// } Driver Code Ends