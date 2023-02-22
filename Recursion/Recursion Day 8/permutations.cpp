#include <bits/stdc++.h>
using namespace std;

void permutations(string p, string up)
{
    if (up.length() == 0)
    {   
        cout << p << " ";
       
        return;
    }

    char ch = up[0];
    for (int i = 0; i <= p.length(); i++)
    {
        string f = p.substr(0,i);
    

        string s = p.substr(i,p.length());
   

      

        permutations(f + ch + s, up.substr(1));
    }
}

void solve(vector<int> nums, vector<vector<int>> &ans, int index)
{
    if (index >= nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int j = index; j < nums.size(); j++)
    {
        swap(nums[index], nums[j]);

        solve(nums, ans, index + 1);
        swap(nums[index], nums[j]);
    }
}
    vector<vector<int>> permute(vector<int> & nums)
    {
        vector<vector<int>> ans;
        int index = 0;
        solve(nums, ans, index);
        return ans;
    }

    int main()
    {
        string s = "abc";
        permutations("",s);
       

        
      

    // vector<int>nums{1,2,3};
    

    
    // vector<vector<int>>ans= permute(nums);
   

    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for (int j = 0; j < ans[0].size(); j++)
    //     {
    //        cout<<ans[i][j]<<",";
    //     }
    //     cout<<endl;
    // }
    

        return 0;
    }