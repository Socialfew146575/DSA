#include <bits/stdc++.h>
using namespace std;

void longestCommonSubsequence(string text1, string text2)
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

    int i=n1, j=n2;
    string ans="";
    while(i>0 && j>0){


        if(text1[i-1]==text2[j-1]){
            ans+=text1[i-1];
            i--;
            j--;

        }

        else if(dp[i][j-1]>dp[i-1][j]){
            j--;
        }
        else i--;




    }

    reverse(ans.begin(),ans.end());
    cout<< ans;
     
}

int main(){

    string text1 = "abcde", text2 = "ace";
    longestCommonSubsequence(text1, text2);
    return 0;
}