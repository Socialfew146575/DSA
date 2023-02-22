#include <bits/stdc++.h>
using namespace std;

// void reverse(string&s, int i, int j)
// {

//     if (i > j)
//     {
//         return;
//     }

//     swap(s[i], s[j]);

//     reverse(s, i + 1, j - 1);
// }
void reverse(string&s, int i)
{

    if (i >s.length()-i-1)
    {
        return;
    }

    swap(s[i], s[s.length()-i-1]);

    reverse(s, i + 1);
}

int main()
{
    string s = "abcde";
    reverse(s, 0);
    // reverse(s, 0, s.length() - 1);
    cout << s;

    return 0;
}