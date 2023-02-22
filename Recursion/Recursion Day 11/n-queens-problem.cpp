#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<bool>> board, int row, int col)
{

    for (int i = 0; i < row; i++)
    {
        if (board[i][col])
        {
            return false;
        }
    }

    for (int i = 1; i <= min(row, col); i++)
    {
        if (board[row - i][col - i])
        {
            return false;
        }
    }
    int n = board.size();
    int maxRight = min(row, n - col - 1);

    for (int i = 1; i <= maxRight; i++)
    {
        if (board[row - i][col + i])
        {
            return false;
        }
    }
}

void display(vector<vector<bool>> board)
{
    cout << endl;
    cout << endl;
    for (auto row : board)
    {
        for (auto element : row)
        {
            if (element == true)
            {
                cout << "Q"
                     << " ";
            }
            else
            {
                cout << "X"
                     << " ";
            }
        }
        cout << endl;
    }
}

int queens(vector<vector<bool>> board, int row)
{

    if (row == board.size())
    {

        display(board);

        return 1;
    }
    int count = 0;

    for (int col = 0; col < board.size(); col++)
    {   
        
        if (isSafe(board, row, col))
        {   
        
            board[row][col] = true;
        
            count += queens(board, row + 1);
            board[row][col] = false;
        
        }
    }

    return count;
}

int main()
{

    vector<vector<bool>> board{{false, false, false, false}, {false, false, false, false}, {false, false, false, false}, {false, false, false, false}};
    cout<<queens(board,0);

    return 0;
}