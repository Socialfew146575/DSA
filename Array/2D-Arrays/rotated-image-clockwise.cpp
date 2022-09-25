#include <bits/stdc++.h>
using namespace std;
void rotate_90(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {

        for (int j = i; j < matrix.size(); j++)
        {

            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // for (int i = 0; i < matrix.size(); i++)
    // {
    //     int left = 0, right = matrix.size() - 1;

    //     while (left < right)
    //     {
    //         swap(matrix[i][left], matrix[i][right]);
    //         ++left;
    //         --right;
    //     }
    // }

    for (int i = 0; i < matrix.size(); i++)
    {

        reverse(matrix[i].begin(), matrix[i].end());
    }
}
void rotate_180(vector<vector<int>> &matrix)
{

    // for (int i = 0; i < matrix.size(); i++)
    // {
    //     int left = 0, right = matrix.size() - 1;

    //     while (left < right)
    //     {
    //         swap(matrix[i][left], matrix[i][right]);
    //         ++left;
    //         --right;
    //     }
    // }

    for (int i = 0; i < matrix.size(); i++)
    {

        reverse(matrix[i].begin(), matrix[i].end());
    }

    reverse(matrix.begin(), matrix.end());

    // for (int i = 0; i < matrix.size(); i++)
    // {
    //     int top=0;int bottom=matrix.size()-1;
    //     while (top<bottom)
    //     {
    //         swap(matrix[top],matrix[bottom]);
    //         top++;
    //         bottom--;
    //     }

    // }
}
void rotate_270(vector<vector<int>> &matrix)
{

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = i; j < matrix.size(); j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    reverse(matrix.begin(), matrix.end());

    // for (int i = 0; i < matrix.size(); i++)
    // {
    //     int top=0;int bottom=matrix.size()-1;
    //     while (top<bottom)
    //     {
    //         swap(matrix[top],matrix[bottom]);
    //         top++;
    //         bottom--;
    //     }

    // }
}
int main()
{
    vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    rotate_90(matrix1);

    for (int i = 0; i < matrix1.size(); i++)

    {
        for (int j = 0; j < matrix1[0].size(); j++)
        {
            cout << matrix1[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl
         << endl
         << endl;

    vector<vector<int>> matrix2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate_180(matrix2);

    for (int i = 0; i < matrix2.size(); i++)

    {
        for (int j = 0; j < matrix2[0].size(); j++)
        {
            cout << matrix2[i][j] << " ";
        }

        cout << endl;
    }
    cout << endl
         << endl
         << endl;

    vector<vector<int>> matrix3 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate_270(matrix3);

    for (int i = 0; i < matrix3.size(); i++)

    {
        for (int j = 0; j < matrix3[0].size(); j++)
        {
            cout << matrix3[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}