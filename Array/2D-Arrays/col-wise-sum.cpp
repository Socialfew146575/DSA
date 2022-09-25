#include <iostream>
using namespace std;

int main()
{

    int row, col;
    cout << "Enter the number of rows you want in the array ";
    cin >> row;
    cout << "Enter the number of cols you want in the array ";
    cin >> col;

    // Create 2D-array
    int matrix[row][col];

    // Taking input
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int ans[row] = {0};

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            ans[i] += matrix[j][i];
        }
    }

    for (int i = 0; i < row; i++)
    {
        cout << "Col-Wise-Sum of row " << i + 1 << " is " << ans[i] << endl;
    }

    return 0;
}