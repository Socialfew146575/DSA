#include <bits/stdc++.h>
using namespace std;

string longestCommonSubsequence(string text1, string text2)
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

    string ans = "";
    int i = n1, j = n2;

    while (i > 0 && j > 0)
    {

        if (text1[i - 1] == text2[j - 1])
        {

            ans += text1[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {

            ans += text1[i - 1];
            i--;
        }
        else
        {
            ans += text2[j - 1];
            j--;
        }
    }

    while (i > 0)
    {
        ans += text1[i - 1];
        i--;
    }
    while (j > 0)
    {
        ans += text2[j - 1];
        j--;
    }

    return ans;
}

string shortestCommonSupersequence(string str1, string str2)
{

    string ans = longestCommonSubsequence(str1, str2);
    reverse(ans.begin(), ans.end());

    return ans;
}
int longestCommonSubsequence2(string text1, string text2)
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

int lengthOfShortestCommonSupersequence(string str1, string str2)
{

    int len = longestCommonSubsequence2(str1, str2);
   
    int ans = str1.length() + str2.length() - len;
    return ans;
}

int main()
{

    string str1 = "abac", str2 = "cab";

    cout << shortestCommonSupersequence(str1, str2) << endl;
    cout << lengthOfShortestCommonSupersequence(str1, str2) << endl;

    return 0;
}