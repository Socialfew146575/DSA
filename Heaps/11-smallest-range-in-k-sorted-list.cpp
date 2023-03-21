#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    int row;
    int col;

    node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare
{

public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &kArrays, int k, int n)
{
    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue<node *, vector<node *>, compare> minHeap;

    for (int i = 0; i < k; i++)
    {
        node *temp = new node(kArrays[i][0], i, 0);
        maxi=max(maxi,temp->data);
        mini=min(mini,temp->data);
        minHeap.push(temp);
    }

    int start=mini,end=maxi;

    while (!minHeap.empty())
    {   
        node*temp=minHeap.top();
        minHeap.pop();

        mini=temp->data;

        if(maxi-mini < end-start){
            start=mini;
            end=maxi;
        }

        if(temp->col+1<n){
            maxi=max(maxi,kArrays[temp->row][temp->col+1]);
            
            minHeap.push(new node(kArrays[temp->row][temp->col+1],temp->row,temp->col+1));
        }
        else{
            break;
        }



    }

    return end-start+1;
       
}

int main()
{
    vector<vector<int>> kArrays = {{1, 10, 11}, {2, 3, 20}, {5, 6, 12}};
    int k = 3;
    int n = 3;
    int ans = kSorted(kArrays, k, n);
    cout << ans;
    return 0;
}