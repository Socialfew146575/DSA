#include <iostream>
#include <vector>
using namespace std;
vector<int> spiralPathMatrix(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int n = matrix.size();
    int m = matrix[0].size();
    int count = 0;
    int total = m * n;
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = n - 1;
    int endingCol = m - 1;

    while (count < total)
    {

        for (int index = startingCol; index <= endingCol && count < total; index++)
        {
            ans.push_back(matrix[startingRow][index]);
            count++;
        }
        startingRow++;

        for (int index = startingRow; index <= endingRow && count < total; index++)
        {
            ans.push_back(matrix[index][endingCol]);
            count++;
        }
        endingCol--;
        for (int index = endingCol; index >= startingCol && count < total; index--)
        {
            ans.push_back(matrix[endingRow][index]);
            count++;
        }
        endingRow--;

        for (int index = endingRow; index >= startingRow && count < total; index--)
        {
            ans.push_back(matrix[index][startingCol]);
            count++;
        }
        startingCol++;
    }

    return ans;
}
int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ans = spiralPathMatrix(matrix);

    for (int i = 0; i < ans.size(); i++)

    {
        cout << ans[i] << " ";
    }

    return 0;
}