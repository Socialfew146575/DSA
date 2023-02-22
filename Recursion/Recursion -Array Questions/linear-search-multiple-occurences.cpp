#include <bits/stdc++.h>
using namespace std;

void linearSearch(int *arr, int n, int target, vector<int> &ans)
{

    if (n == 0)
    {

        return;
    }

    if (arr[n - 1] == target)
    {
        ans.push_back(n - 1);
    }
    linearSearch(arr, n - 1, target, ans);
}

vector<int> find(int *arr, int n, int index, int target, vector<int> ans)
{

   

    if (index == n)
    {
        return ans;
    }

    if (arr[index] == target)
    {
        ans.push_back(index);
    }

    return find(arr, n, ++index, target,ans);
}

vector<int> l_Search(int *arr, int n, int index, int target)
{

    vector<int> ans;

    if (index == n)
    {
        return ans;
    }

    if (arr[index] == target)
    {
        ans.push_back(index);
    }

    vector<int>v= l_Search(arr, n, ++index, target);

   for (int i = 0; i < v.size(); i++)
   {
    ans.push_back(v[i]);
   }


   
    return ans;

   
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    // vector<int> ans;
    // linearSearch(arr, n, target, ans);

    // vector<int> res = find(arr, n, 0, target,res);

    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }

    // cout << endl;
   
    // for (int i = 0; i < res.size(); i++)
    // {
    //     cout << res[i] << " ";
    // }

    vector<int>ans=l_Search(arr,n,0,target);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}