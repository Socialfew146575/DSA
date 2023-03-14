#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int i, int n)
{

    int largest = i;
    int left = 2 * i+1 ;
    int right = 2 * i+2;

    if (left<n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right<n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, largest, n);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    vector<int> c;
    for (auto i : a)
    {
        c.push_back(i);
    }
    for (auto i : b)
    {
        c.push_back(i);
    }
    int s=c.size();
    for (int i = s / 2-1; i >= 0; i--)
    {
        heapify(c, i,s);
    }

    return c;
}
int main()
{

    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};

    vector<int> c = mergeHeaps(a, b, a.size(), b.size());

    for (auto i:a)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    for (auto i:b)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    for (auto i:c)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    

    return 0;
}