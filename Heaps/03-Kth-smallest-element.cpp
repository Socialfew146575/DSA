#include <bits/stdc++.h>
using namespace std;


int kthSmallest(vector<int>arr,int l,int r,int k){

    priority_queue<int>pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = k; i <= r; i++)
    {
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
    
    

}

int main()
{

    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k=3;

    cout<<k<<"rd smallest element in the array is "<<kthSmallest(arr,0,arr.size()-1,k);
    
    return 0;
}