#include <bits/stdc++.h>
using namespace std;

void display(int board[9][9])
{

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int board[9][9], int row, int col, int num)
{

    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == num)
        {
            return false;
        }
    }

    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == num)
        {
            return false;
        }
    }

    int start = row - row % 3;
    int end = col - col % 3;

    for (int r = start; r < start + 3; r++)
    {
        for (int c = end; c < end + 3; c++)
        {
            if (board[r][c] == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool solve(int board[9][9])
{

    int row = -1;
    int col = -1;

    bool emptyLeft = true;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
            {
                row = i;
                col = j;
                emptyLeft = false;
                break;
            }
        }

        if (emptyLeft == false)
        {

            break;
        }
    }
    if (emptyLeft)
    {
        return true;
    }

    for (int number = 1; number < 10; number++)
    {
        if (isSafe(board, row, col, number))
        {
            board[row][col] = number;
            if (solve(board))
            {

                return true;
            }
            else
            {
                board[row][col] = 0;
            }
        }
    }

    return false;
}

int main()
{
    int board[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    if (solve(board))
    {
        display(board);
    }
    else
    {
        cout << "cannot be solved";
    }

    return 0;
}