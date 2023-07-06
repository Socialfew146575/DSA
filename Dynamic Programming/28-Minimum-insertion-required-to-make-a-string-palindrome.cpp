

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int longestPalindromeSubseq(string s)
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

public:
    int findMinInsertions(string s)
    {
        // code here
        return s.length() - longestPalindromeSubseq(s);
    }
};

//{ Driver Code Starts.

int main()
{

    string S = "leetcode";

    Solution ob;
    cout << ob.findMinInsertions(S) << endl;

    return 0;
}

// } Driver Code Ends