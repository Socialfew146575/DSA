#include <iostream>
#include <vector>
using namespace std;
bool isPossible(vector<int> &nums, int m, int mid)
{
    int count = 1;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] + sum <= mid)
        {
            sum += nums[i];
        }

        else
        {
            count++;
            if ((count > m) || (nums[i] > mid))
            {
                return false;
            }

            sum=nums[i];
        }
    }
    return true;
}

int splitArray(vector<int> &nums, int m)
{
    int s = -1;
    int e = 0;
    int ans = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        s = max(s, nums[i]);
        e = e + nums[i];
    }
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (isPossible(nums, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}


int main()
{

    vector<int> nums = {7, 2, 5, 10, 8};
    cout << splitArray(nums, 2);

    return 0;
}