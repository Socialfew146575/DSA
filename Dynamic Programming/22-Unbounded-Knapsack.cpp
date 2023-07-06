#include <bits/stdc++.h>
using namespace std;

int solve(int n, int W, int val[], int wt[])
{

    if (n == 0)
    {

        if (wt[0] <= W)
            return W / wt[0] * (val[0]);

        return 0;
    }

    int notTaken = solve(n - 1, W, val, wt);
    int taken = INT_MIN;

    if (wt[n] <= W)
        taken = val[n] + solve(n, W - wt[n], val, wt);

    return max(notTaken, taken);
}

int knapSack(int N, int W, int val[], int wt[])
{
    // code here

    return solve(N - 1, W, val, wt);
}

int solve2(int n, int W, int val[], int wt[], vector<vector<int>> &dp)
{

    if (n == 0)
    {

        if (wt[0] <= W)
            return W / wt[0] * (val[0]);

        return 0;
    }

    if (dp[n][W] != -1)
        return dp[n][W];

    int notTaken = solve2(n - 1, W, val, wt, dp);
    int taken = INT_MIN;

    if (wt[n] <= W)
        taken = val[n] + solve2(n, W - wt[n], val, wt, dp);

    return dp[n][W] = max(notTaken, taken);
}

int knapSack2(int N, int W, int val[], int wt[])
{
    // code here

    vector<vector<int>> dp(N, vector<int>(W + 1, -1));
    return solve2(N - 1, W, val, wt, dp);
}
int knapSack3(int N, int W, int val[], int wt[])
{
    // code here

    vector<vector<int>> dp(N, vector<int>(W + 1, 0));

    for (int i = 0; i <= W; i++)
    {

        dp[0][i] = ((int)(i / wt[0])) * val[0];
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j <= W; j++)
        {

            int notTaken = dp[i - 1][j];
            int taken = 0;

            if (wt[i] <= j)
                taken = val[i] + dp[i][j - wt[i]];

            dp[i][j] = max(notTaken, taken);
        }
    }

    return dp[N - 1][W];
}
int knapSack4(int N, int W, int val[], int wt[])
{
    // code here

    // vector<vector<int>>dp(N,vector<int>(W+1,0));

    vector<int> prev(W + 1, 0), curr(W + 1);

    for (int i = 0; i <= W; i++)
    {

        prev[i] = ((int)(i / wt[0])) * val[0];
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j <= W; j++)
        {

            int notTaken = prev[j];
            int taken = 0;

            if (wt[i] <= j)
                taken = val[i] + curr[j - wt[i]];

            curr[j] = max(notTaken, taken);
        }
        prev = curr;
    }

    return prev[W];
}
int knapSack5(int N, int W, int val[], int wt[])
{
    

    vector<int> prev(W + 1, 0);

    for (int i = 0; i <= W; i++)
    {

        prev[i] = ((int)(i / wt[0])) * val[0];
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j <= W; j++)
        {

            int notTaken = prev[j];
            int taken = 0;

            if (wt[i] <= j)
                taken = val[i] + prev[j - wt[i]];

            prev[j] = max(notTaken, taken);
        }
    }

    return prev[W];
}


int main()
{
    int N = 2, W = 3;
    int val[] = {1, 1};
    int wt[] = {2, 1};

    cout << knapSack(N, W, val, wt) << endl;
    cout << knapSack2(N, W, val, wt) << endl;
    cout << knapSack3(N, W, val, wt) << endl;
    cout << knapSack4(N, W, val, wt) << endl;
    cout << knapSack5(N, W, val, wt) << endl;
    return 0;
}