#include <bits/stdc++.h>
using namespace std;

// void pattern(int n)
// {

//     if (n == 0)
//     {
//         return;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         cout << "*"
//              << " ";
//     }
//     cout << endl;

//     pattern(n - 1);
// }

void pattern(int r, int c)
{
    if (r == 0)
    {
        return;
    }

    if (c < r)
    {
        cout << "*"
             << " ";
        pattern(r, c + 1);
    }
    else
    {
        cout << endl;
        pattern(r - 1, 0);
    }
}
void pattern2(int r, int c)
{
    if (r == 0)
    {
        return;
    }

    if (c < r)
    {
       
        pattern2(r, c + 1);
         cout << "*"
             << " ";
    }
    else
    {
        pattern2(r - 1, 0);
        
        cout << endl;
    }
}

int main()
{

    // pattern(5);
    pattern(5, 0);
    pattern2(5, 0);
    return 0;
}