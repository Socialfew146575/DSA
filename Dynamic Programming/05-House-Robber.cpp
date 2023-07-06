// You are a professional robber planning to rob houses along a street.Each house has a certain amount of money stashed.All houses at this place are arranged in a circle.That means the first house is the neighbor of the last one.Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

//    Given an integer array nums representing the amount of money of each house,
//     return the maximum amount of money you can rob tonight without alerting the police.

#include <bits/stdc++.h>
using namespace std;
class Solution
{

    int solve(int n, vector<int> &nums, vector<int> &dp)
    {

        if (n == 0)
            return nums[0];

        if (n < 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int pick = nums[n] + solve(n - 2, nums, dp);
        int notPick = solve(n - 1, nums, dp);

        dp[n] = max(pick, notPick);

        return dp[n];
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> first;
        vector<int> last;
        if (n == 1)
            return nums[0];

        for (int i = 0; i < n; i++)
        {

            if (i != 0)
                last.push_back(nums[i]);
            if (i != n - 1)
                first.push_back(nums[i]);
        }

        vector<int> dp1(n - 1, -1);
        vector<int> dp2(n - 1, -1);

        return max(solve(n - 2, first, dp1), solve(n - 2, last, dp2));
    }
};
int main()
{

    Solution S;
    vector<int> house{2, 3, 2};
    cout << S.rob(house);
    return 0;
}