#include <bits/stdc++.h>
using namespace std;

// LONGEST COMMON SUBSEQUENCE

int solve(int n1, int n2, string text1, string text2)
{

    if (n1 < 0 || n2 < 0)
        return 0;

    if (text1[n1] == text2[n2])
        return 1 + solve(n1 - 1, n2 - 1, text1, text2);

    else
    {

        return max(solve(n1 - 1, n2, text1, text2), solve(n1, n2 - 1, text1, text2));
    }
}

int longestCommonSubsequence(string text1, string text2)
{

    int n1 = text1.length() - 1;
    int n2 = text2.length() - 1;

    return solve(n1, n2, text1, text2);
}
int solve2(int n1, int n2, string text1, string text2, vector<vector<int>> &dp)
{

    if (n1 < 0 || n2 < 0)
        return 0;

    if (dp[n1][n2] != -1)
        return dp[n1][n2];

    if (text1[n1] == text2[n2])
        return dp[n1][n2] = 1 + solve2(n1 - 1, n2 - 1, text1, text2, dp);

    else
    {

        return dp[n1][n2] = max(solve2(n1 - 1, n2, text1, text2, dp), solve2(n1, n2 - 1, text1, text2, dp));
    }
}

int longestCommonSubsequence2(string text1, string text2)
{

    int n1 = text1.length() - 1;
    int n2 = text2.length() - 1;

    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
    return solve2(n1, n2, text1, text2, dp);
}

int longestCommonSubsequence3(string text1, string text2)
{

    int n1 = text1.length();
    int n2 = text2.length();

    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

    for (int i = 0; i <= n1; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= n2; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {

            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];

            else
            {

                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n1][n2];
}
int longestCommonSubsequence4(string text1, string text2)
{

    int n1 = text1.length();
    int n2 = text2.length();

    vector<int> prev(n2 + 1, 0), curr(n2 + 1);

    for (int i = 0; i <= n2; i++)
    {
        prev[i] = 0;
    }

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {

            if (text1[i - 1] == text2[j - 1])
                curr[j] = 1 + prev[j - 1];

            else
            {

                curr[j] = max(prev[j], curr[j - 1]);
            }
        }
        prev = curr;
    }

    return prev[n2];
}
int main()
{
    string text1 = "abcde", text2 = "ace";
    cout << longestCommonSubsequence(text1, text2) << endl;
    cout << longestCommonSubsequence2(text1, text2) << endl;
    cout << longestCommonSubsequence3(text1, text2) << endl;
    cout << longestCommonSubsequence4(text1, text2) << endl;
    return 0;
}