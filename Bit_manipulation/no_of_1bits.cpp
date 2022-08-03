#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int count = 0;
    while (n != 0)
    {
        // n &= n - 1;
        // count++;    ---------------------->ALTERNATE METHOD

        if (n & 1)
        {
            count++;
        }

        n = n >> 1;
    }
    cout << count;
    return 0;
}

// if the last bit is 1 it will give 1 on operating & with 1 and count will be incremented and then the number will be right shifted and the process will continue till the number becomes zero...