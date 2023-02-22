
// i/p = 412
// o/p = four one two

#include <bits/stdc++.h>
using namespace std;
string arr[10] = {"zero",
                  "one",
                  "two",
                  "three",
                  "four",
                  "five",
                  "six",
                  "seven",
                  "eight",
                  "nine"};
void sayDigits(int n)
{
    // base case
    if (n == 0)
    {

        return;
    }
    // processing
    int digit = n % 10;
    n = n / 10;

    // recursive call
    sayDigits(n);


    cout << arr[digit] << " ";
}

int main()
{

    int n;
    cin >> n;
    sayDigits(n);
    return 0;
}