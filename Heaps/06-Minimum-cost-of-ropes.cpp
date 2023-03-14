#include <bits/stdc++.h>
using namespace std;

int minimumCostOfRope(vector<int> arr)
{

    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());

    int cost = 0;
    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        cost += a + b;
        pq.push(a + b);
    }
    return cost;
}

int main()
{

    vector<int> arr = {4, 3, 2, 6};
    cout << minimumCostOfRope(arr);
    return 0;
}