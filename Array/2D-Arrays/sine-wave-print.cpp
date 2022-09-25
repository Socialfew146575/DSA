#include <bits/stdc++.h>
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;
    for (int i = 0; i < mCols; i++)
    {

        if (i % 2 == 0)
        {
            for (int j = 0; j < nRows; j++)
            {

                ans.push_back(arr[j][i]);
            }
        }
        else
        {

            for (int j = nRows - 1; j >= 0; j--)
            {

                ans.push_back(arr[j][i]);
            }
        }
    }

    return ans;
}

int main()
{
    int row, col;
    cout << "Enter the number of rows you want in the array ";
    cin >> row;
    cout << "Enter the number of cols you want in the array ";
    cin >> col;

    vector<vector<int>> v;

    
    int element;
    for (int i = 0; i < row; i++)
    {   vector<int> colElement;
        for (int j = 0; j < col; j++)
        {
            cin >> element;
            colElement.push_back(element);
        }

        
  
        v.push_back(colElement);
    }

    vector<int> ans = wavePrint(v, row, col);

    for (int i = 0; i < row * col; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}