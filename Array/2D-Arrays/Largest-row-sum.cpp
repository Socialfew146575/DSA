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

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            ans[i] += matrix[i][j];
        }
    }

    int max=ans[0];
    int largestrow=0;
    for (int i = 0; i < row; i++)
    {
        if (max<ans[i])
        {
            max=ans[i];
            largestrow=i;
        }
        
    }

    cout<<"Largest row is row "<<largestrow+1<<" with the sum of "<<max<<endl;

    return 0;
}