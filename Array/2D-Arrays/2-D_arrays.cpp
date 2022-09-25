#include <iostream>
using namespace std;

bool isPresent(int arr[][4], int target, int row, int col)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == target)
            {   
                cout<<"at index"<<"["<<i<<"]"<<"["<<j<<"]"<<endl;
                return true;
            }
        }
    }

    return 0;
}
int main()
{

    int row, col;
    cout << "Enter the number of rows you want in the array ";
    cin >> row;
    cout << "Enter the number of cols you want in the array ";
    cin >> col;

    // Create 2D-array
    int matrix[row][4];

    // Taking input
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // Printing
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    cout << "Enter the element to search " << endl;
    int target;
    cin >> target;

    if (isPresent(matrix, target, 3, 4))
    {
        cout << "Element found " << endl;
    }
    else{

        cout<<"Not found"<<endl;
    }

    return 0;
}