#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstr(string s1, string s2, int n, int m)
{
    // your code here

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= m; j++)
        {

            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];

            else
                dp[i][j] = 0;
        }
    }

    int maxi = -1e9;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {

            maxi = max(maxi, dp[i][j]);
        }
    }

    return maxi;
}
int longestCommonSubstr2(string s1, string s2, int n, int m)
{
    // your code here

    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    int maxi = -1e9;
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= m; j++)
        {

            if (s1[i - 1] == s2[j - 1])
            {
                curr[j] = 1 + prev[j - 1];
                maxi = max(maxi, curr[j]);
            }

            else
                curr[j] = 0;
        }
        prev=curr;
    }

    return maxi;
}

int main()
{

    string S1 = "ABCDGH", S2 = "ACDGHR";
    int n = 6, m = 6;

    cout << longestCommonSubstr(S1, S2, n, m) << endl;
    cout << longestCommonSubstr2(S1, S2, n, m) << endl;


    return 0;
}