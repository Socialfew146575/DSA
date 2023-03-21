#include <bits/stdc++.h>
using namespace std;

int bruteForce(vector<int> arr, int k)
{

    vector<int> ans;

    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            ans.push_back(sum);
        }
    }

    sort(ans.begin(), ans.end());

    return ans[ans.size() - k];
}

int optimized(vector<int> arr, int k)
{

    priority_queue<int, vector<int>, greater<int> > mini;
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            if (mini.size() < k)
            {
                mini.push(sum);
            }
            else
            {
                if (sum > mini.top())
                {
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }
    return mini.top();
}

int main()
{

    vector<int> arr = {3, -2, 5};
    int k = 3;

    cout << bruteForce(arr, k);
    cout<<endl;
    cout << optimized(arr, k);

    return 0;
}