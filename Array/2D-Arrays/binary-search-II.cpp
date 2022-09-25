#include <bits/stdc++.h>
using namespace std;
// matrix is sorted row wise and column wise..

vector<int> search(vector<vector<int>> &matrix, int target)
{
    vector<int> ans(2, -1);
    int m = matrix.size();
    int n = matrix[0].size();

    int s = 0;
    int e = n - 1;

    while (s < m && e > 0)
    {
        if (matrix[s][e] == target)
        {

            ans[0] = s;
            ans[1] = e;
            break;
        }

        else if (matrix[s][e] < target)
        {

            s++;
        }
        else
        {
            e--;
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{10, 20, 30, 40}, {15, 25, 35, 45}, {28, 29, 37, 49}, {33, 34, 38, 50}};

    cout << "Is 37 present in the matrix:=> ";
    vector<int> ans = search(matrix, 37);

    cout << ans[0] << " " << ans[1];

    return 0;
}