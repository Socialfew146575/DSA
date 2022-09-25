// A jagged array is an array of arrays such that member arrays can be of different sizes, i.e., we can create a 2-D array but with a variable number of columns in each row. These types of arrays are also known as Jagged arrays.

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int row;
    cin >> row;

    int *col = new int[row];

    int **arr = new int *[row];

    for (int i = 0; i < row; i++)
    {
        cin >> col[i];

        arr[i] = new int[col[i]];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col[i]; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col[i]; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}