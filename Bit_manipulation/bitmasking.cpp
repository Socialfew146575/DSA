#include <iostream>
using namespace std;

int main()
{
    //    **************** Even-Odd---->even number gives 0 on operating (bitwise &) with 1 while odd number gives 1...****************
    // Here the mask is 1
    // int n;
    // cin >> n;
    // if (n & 1)
    // {
    //     cout << "odd";
    // }
    // else
    // {
    //     cout << "Even";
    // }

    //    ************************** find the i th bit*****************************

    // int n, i;
    // cin >> n >> i;
    // int mask = 1 << i;
    // if (n & mask)
    // {
    //     cout << "1";
    // }
    // else
    // {
    //     cout << "0";
    // }

    //    *********************************** Set the i th bit**********************************

    // int n, i;
    // cin >> n >> i;
    // int mask = 1 << i;

    // n = n | mask;
    // cout << n;

    //  **********************************   Clear the ith bit*********************************

    // int n, i;
    // cin >> n >> i;
    // int mask = ~(1 << i);
    // n = n & mask;
    // cout << n;

    // int n, i;
    // cin >> n >> i;
    // int mask = 1 << i;
    // n = n ^ mask;
    // cout << n;

    // **********************************find the number of bits to change to convert a to b******************************

    // int a, b;
    // cin >> a >> b;

    // int n = a ^ b;
    // int count = 0;

    // while (n>0)
    // {
    //     n=n & (n - 1);
    //     count++;
       
    // }
    // cout << count;
    

    // int a, b;
    // cin >> a >> b;
    // int n = a ^ b;
    // while (n != 0)
    // {
    //     if (n & 1)
    //     {
    //         count++;
    //     }
    //     n = n >> 1;
    // }
    // cout << count;
    return 0;
}
