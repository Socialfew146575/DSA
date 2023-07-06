#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(int n, vector<int> &nums)
{

    if (n == 0)
        return nums[0];

    if (n < 0)
        return 0;

    int pick = nums[n] + solve(n - 2, nums);
    int notPick = 0 + solve(n - 1, nums);

    return max(pick, notPick);
}

int maxSum(vector<int> &elements)
{

    int n = elements.size() - 1;

    return solve(n, elements);
}

// Memoization
int solve2(int n, vector<int> &nums, vector<int> &dp)
{

    if (n == 0)
        return nums[0];

    if (n < 0)
        return 0;

    int pick = nums[n] + solve2(n - 2, nums, dp);
    int notPick = 0 + solve2(n - 1, nums, dp);

    return max(pick, notPick);
}

int maxSum2(vector<int> &elements)
{

    int n = elements.size() - 1;
    vector<int> dp(n + 1, -1);
    return solve2(n, elements, dp);
}
// Tabulatiton
int solve3(int n, vector<int> &nums, vector<int> &dp)
{

   dp[0]=nums[0];

   for (int i = 1; i <= n; i++)
   {
        int pick = nums[i];
        if(i>1) pick+=nums[i-2];

        int notPick = 0 + dp[i-1];

        dp[i]=max(pick,notPick);
   }
   
    return dp[n];
}

int maxSum3(vector<int> &elements)
{

    int n = elements.size() - 1;
    vector<int> dp(n + 1, -1);
    return solve3(n, elements, dp);
}// spaceoptimization

int maxSum4(vector<int> &nums)
{

    int n = nums.size() - 1;
    int last1 = nums[0];
    int last2 = 0;

    for (int i = 1; i <= n; i++)
    {

        int pick = nums[i];
        if (i > 1)
            pick += last2;
        int notPick = 0 + last1;

        int curr = max(pick, notPick);
        last2 = last1;
        last1 = curr;
    }
    return last1;
}

int main()
{

    vector<int> elements = {1, 2, 3, 1};
    cout << maxSum(elements) << endl;
    cout << maxSum2(elements) << endl;
    cout << maxSum3(elements) << endl;
    cout << maxSum4(elements) << endl;

    return 0;
}