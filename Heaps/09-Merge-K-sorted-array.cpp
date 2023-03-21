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

vector<int> mergeKSortedArrays(vector<vector<int> > &kArrays, int k)
{
    vector<int> ans;
    priority_queue<node *, vector<node *>, compare> minHeap;

    for (int i = 0; i < k; i++)
    {
        node *temp = new node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }

    while (minHeap.size() > 0)
    {
        node *temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();

        int i = temp->row;
        int j = temp->col;

        if (j + 1 < kArrays[i].size())
        {
            node *nod = new node(kArrays[i][j + 1], i, j + 1);
            minHeap.push(nod);
        }
    }

    return ans;
}

int main()
{
    vector<vector<int> > kArrays = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int k = 3;
    vector<int> ans = mergeKSortedArrays(kArrays, k);
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}