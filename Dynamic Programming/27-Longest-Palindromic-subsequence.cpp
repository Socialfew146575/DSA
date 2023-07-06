#include <bits/stdc++.h>
using namespace std;

int solve(int n1, int n2, string s1, string s2)
{

    if (n1 < 0 || n2 < 0)
    {
        return 0;
    }

    if (s1[n1] == s2[n2])
    {

        return 1 + solve(n1 - 1, n2 - 1, s1, s2);
    }
    else
    {

        return max(solve(n1 - 1, n2, s1, s2), solve(n1, n2 - 1, s1, s2));
    }
}

int longestPalindromeSubseq(string s)
{
    string s2 = s;
    reverse(s.begin(), s.end());

    int n = s.length() - 1;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solve(n, n, s, s2);
}
int solve2(int n1, int n2, string s1, string s2, vector<vector<int>> &dp)
{

    if (n1 < 0 || n2 < 0)
    {
        return 0;
    }

    if (dp[n1][n2] != -1)
        return dp[n1][n2];

    if (s1[n1] == s2[n2])
    {

        return dp[n1][n2] = 1 + solve2(n1 - 1, n2 - 1, s1, s2, dp);
    }
    else
    {

        return dp[n1][n2] = max(solve2(n1 - 1, n2, s1, s2, dp), solve2(n1, n2 - 1, s1, s2, dp));
    }
}

int longestPalindromeSubseq2(string s)
{
    string s2 = s;
    reverse(s.begin(), s.end());

    int n = s.length() - 1;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solve2(n, n, s, s2, dp);
}

int longestPalindromeSubseq3(string s)
{
    string s2 = s;
    reverse(s.begin(), s.end());

    int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            if (s[i - 1] == s2[j - 1])
            {

                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {

                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][n];
}
int longestPalindromeSubseq4(string s)
{
    string s2 = s;
    reverse(s.begin(), s.end());

    int n = s.length();
    vector<int> prev(n + 1, 0), curr(n + 1, 0);

    for (int i = 0; i <= n; i++)
    {
        prev[i] = prev[0] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            if (s[i - 1] == s2[j - 1])
            {

                curr[j] = 1 + prev[j - 1];
            }
            else
            {

                curr[j] = max(prev[j], curr[j - 1]);
            }
        }

        prev = curr;
    }

    return prev[n];
}

// Printing Longest Palindromic

void printPalindromeSubseq(string s)
{
    string s2 = s;
    reverse(s.begin(), s.end());

    int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            if (s[i - 1] == s2[j - 1])
            {

                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {

                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int i = n, j = n;
    string ans = "";

    while (i > 0 && j > 0)
    {
        if (s[i-1] == s2[j-1])
        {
            ans += s[i-1];
            i--;
            j--;
        }

        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
            j--;
    }

    cout << ans << endl;
}

int main()
{

    string s = "bbbab";
    cout << longestPalindromeSubseq(s) << endl;
    cout << longestPalindromeSubseq2(s) << endl;
    cout << longestPalindromeSubseq3(s) << endl;
    cout << longestPalindromeSubseq4(s) << endl;

    printPalindromeSubseq(s);

    return 0;
}