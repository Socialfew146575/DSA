#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve1(int n, vector<vector<int>> &points, int last)
{
    if (n == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {

            if (i == last)
                continue;
            maxi = max(maxi, points[0][i]);
        }
        return maxi;
    }

    int maxi = -1;
    for (int i = 0; i < 3; i++)
    {

        if (i != last)
        {

            int point = points[n][i] + solve1(n - 1, points, i);
            maxi = max(maxi, point);
        }
    }

    return maxi;
}

int ninjaTraining1(int n, vector<vector<int>> &points)
{

    return solve1(n - 1, points, 3);
}

// Memoization
int solve(int n, vector<vector<int>> &points, int last, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {

            if (i == last)
                continue;
            maxi = max(maxi, points[0][i]);
        }
        return maxi;
    }

    if (dp[n][last] != -1)
        return dp[n][last];

    int maxi = -1;
    for (int i = 0; i < 3; i++)
    {

        if (i != last)
        {

            int point = points[n][i] + solve(n - 1, points, i, dp);
            maxi = max(maxi, point);
        }
    }

    dp[n][last] = maxi;
    return dp[n][last];
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, -1));

    // for(int i=0;i<n;i++){

    //     for(int j=0;j<4;j++){
    //         dp[i].push_back(-1);
    //     }

    // }

    return solve(n - 1, points, 3, dp);
}

// Tabulation

int solve2(int n, vector<vector<int>> &points, int last, vector<vector<int>> &dp)
{

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][1], points[0][0]);
    dp[0][3] = max(points[0][1], max(points[0][2], points[0][0]));

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;

            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int point = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }

    return dp[n - 1][3];
}

int ninjaTraining2(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, -1));

    // for(int i=0;i<n;i++){

    //     for(int j=0;j<4;j++){
    //         dp[i].push_back(-1);
    //     }

    // }

    return solve2(n, points, 3, dp);
}

// Space Optimization

int solve3(int n, vector<vector<int>> &points, int last)
{

    vector<int> prev(4);

    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][1], points[0][0]);
    prev[3] = max(points[0][1], max(points[0][2], points[0][0]));

    for (int day = 1; day < n; day++)
    {   
        vector<int>curr(4,0);
        for (int last = 0; last < 4; last++)
        {
            curr[last]=0;

            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int point = points[day][task] + prev[task];
                    curr[last] = max(curr[last], point);
                }
            }
        }
        prev=curr;
    }

    return prev[3];
}

int ninjaTraining3(int n, vector<vector<int>> &points)
{
    

        return solve3(n, points, 3);
}
int main()
{

    int n = 3;

    vector<vector<int>> points = {{1, 2, 5},
                                  {3, 1, 1},
                                  {3, 3, 3}};

    cout << ninjaTraining1(n, points) << endl;
    cout << ninjaTraining(n, points) << endl;
    cout << ninjaTraining2(n, points) << endl;
    cout << ninjaTraining3(n, points) << endl;
}