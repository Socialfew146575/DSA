#include <bits/stdc++.h>
using namespace std;

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

int minOperations(string str1, string str2)
{
    // Your code goes here
    int lcs = longestCommonSubsequence3(str1, str2);

    return str2.length() - lcs + str1.length() - lcs;
}

int main()
{

    string A = "heap", B = "pea";
    cout << minOperations(A, B) << endl;

    return 0;
}