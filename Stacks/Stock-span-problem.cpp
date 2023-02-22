#include <bits/stdc++.h>
using namespace std;

// vector<int> solve(vector<int>arr){

//     vector<int>ans(arr.size());
//     stack<int>st;
//     st.push(-1);

//     for (int i = 0; i < arr.size(); i++)
//     {
//         int curr=arr[i];

//         while (st.top()!=-1 && arr[st.top()]<curr)
//         {
//             st.pop();
//         }
//         ans[i]=i-st.top();
//         st.push(i);
        

//     }
    
// return ans;




// }

vector<int> solve(vector<int>arr){

    vector<int>ans(arr.size());
    stack<pair<int,int>>st;
    st.push({-1,-1});

    for (int i = 0; i < arr.size(); i++)
    {
        int curr=arr[i];

        while (st.top().first !=-1 && st.top().first < curr)
        {
            st.pop();
        }
        ans[i]=i-st.top().second;
        st.push({curr,i});
        

    }
    
return ans;




}


int main(){


vector<int>arr={100,80,60,70,60,75,85};
for (auto i:arr)
{
    cout<<i<<" ";
}
cout<<endl;


vector<int>ans=solve(arr);
for (auto i : ans)
{
    cout << i << " ";
}
cout << endl;

return 0;
}