// Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

#include <bits/stdc++.h>
using namespace std;

    void solve(vector<int>nums,vector<int>output,int index,vector<vector<int>>&ans){
        
        if(index>=nums.size()){
            ans.push_back(output);
            return;
        }
        
        solve(nums,output,index+1,ans);
        
        
        int element=nums[index];
        output.push_back(element);
        solve(nums,output,index+1,ans);
        
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>>ans;
        vector<int>output;
        int index=0;
        
        solve(nums,output,index,ans);
        return ans;
    }

int main(){

vector<int>set{1,2,3};
vector<vector<int>>ans=subsets(set);
for (int i = 0; i < ans.size(); i++)
{
    for (int j = 0; j < ans[i].size(); j++)
    {
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
    
}
cout<<endl;

return 0;
}