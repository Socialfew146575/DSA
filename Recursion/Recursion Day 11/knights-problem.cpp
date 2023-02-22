#include <bits/stdc++.h>
using namespace std;

bool isvalid(vector<vector<bool>> board, int row, int col)
{
    
    if (row >= 0 && row < board.size() && col >= 0 && col < board.size())
    {

        return true;
    }

    return false;
}

bool isSafe(vector<vector<bool>> board, int row, int col)
{   
    if (isvalid(board, row - 2, col - 1))
    {
        if (board[row - 2][col - 1])
        {
            return false;
        }
    }
    if (isvalid(board, row - 1, col - 2))
    {
        if (board[row - 1][col - 2])
        {
            return false;
        }
    }
    if (isvalid(board, row-2, col+1))
    {
        if (board[row - 2][col + 1])
        {
            return false;
        }
    }
    if (isvalid(board, row - 1, col + 2))
    {
        if (board[row - 1][col + 2])
        {
            return false;
        }
    }

    return true;
}

void display(vector<vector<bool>> board)
{
   
     cout<<endl;
    for (auto row : board)
    {
        for (auto element : row)
        {
            if (element == true)
            {
                cout << "K"
                     << " ";
            }
            else
            {
                cout << "_"
                     << " ";
            }
        }
        cout << endl;
    }
}

void knight(vector<vector<bool>> board, int row, int col, int knights)
{   
    

    if (knights == 0)
    {
        display(board);
        cout<<endl;

        return;
    }
    if (row == board.size() - 1 && col == board.size())
    {
        return;
    }

    if (col == board.size())
    {
        knight(board, row + 1, 0, knights);
        return;
    }
    if (isSafe(board, row, col))
    {
        board[row][col] = true;
        knight(board, row, col + 1, knights - 1);
        board[row][col] = false;
    }

    knight(board, row, col + 1, knights);
}

int main()
{
    vector<vector<bool>> board{{false, false, false}, {false, false, false}, {false, false, false}};
    knight(board, 0, 0, 5);

    return 0;
}