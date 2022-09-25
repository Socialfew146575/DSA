#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();

    int s = 0;
    int e = row * col - 1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        int element = matrix[mid / col][mid % col];

        if (element == target)
        {
            return true;
        }

        else if (element > target)
        {

            e = mid - 1;
        }

        else
        {
            s = mid + 1;
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> matrix1 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

    int target = 17;

    cout << searchMatrix(matrix1, target);

    return 0;
}