#include <bits/stdc++.h>
using namespace std;
int solve(int n, vector<int> nums, int target)
{
    if (n == 0)
    {

        if (nums[0] == 0 && target == 0)
            return 2;

        if (target == nums[0] || target == -nums[0])
            return 1;
        else
            return 0;
    }

    int negative = solve(n - 1, nums, target - nums[n]);
    int positive = solve(n - 1, nums, target + nums[n]);

    return positive + negative;
}

int findTargetSumWays(vector<int> &nums, int target)
{
    // Your code here
    int n = nums.size();

    return solve(n - 1, nums, target);
}

int solve2(int n, vector<int> &arr, int sum)
{

    vector<int> prevRow(sum + 1, 0), curr(sum + 1);

    if (arr[0] == 0)
        prevRow[0] = 2;
    else
        prevRow[0] = 1;

    if (arr[0] != 0 && arr[0] <= sum)
        prevRow[arr[0]] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {

            int notTaken = prevRow[j];
            int taken = 0;
            if (arr[i] <= j)
                taken = prevRow[j - arr[i]];

            curr[j] = (taken + notTaken);
        }
        prevRow = curr;
    }

    return prevRow[sum];
}

int findTargetSumWays2(vector<int> &nums, int target)
{
    int n = nums.size();
    int sum = 0;
    for (auto i : nums)
    {
        sum += i;
    }

    if (sum - target < 0 || (sum - target) & 1)
        return 0;
    sum = (sum - target) / 2;
    return solve2(n - 1, nums, sum);
}

int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    cout << findTargetSumWays(nums, target) << endl;
    cout << findTargetSumWays2(nums, target) << endl;

    return 0;
}