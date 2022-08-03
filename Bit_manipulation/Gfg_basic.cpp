#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

int main()
{

    // **********************Detect if two integers have opposite signs**************
    // int a, b;
    // cin >> a >> b;
    // if ((a ^ b) >= 0)
    // {
    //     cout << "Integers dont have opposite sign";
    // }
    // else
    // {
    //     cout << "Opposite sign";
    // }
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@ Add 1 to a given number @@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    // method 1-->least significant 0th bit find kro or jis position me h utne 1 bits se XOR krdo
    // 5->101 mask will be 11
    // int a;
    // cin >> a;
    // int mask = 1;
    // int temp = a;
    // while (temp & 1)
    // {
    //     mask =  (mask<<1)+1;
    //     temp >>= 1;
    // }

    // int res = a ^ mask;
    // cout << res;

    // Method 2--->To add 1 to a number x (say 0011000111), flip all the bits after the rightmost 0 bit (we get 0011000000). Finally, flip the rightmost 0 bit also (we get 0011001000) to get the answer.

    // int a;
    // cin >> a;
    // int m = 1;
    // while (a & m)
    // {
    //     a = a ^ m;
    //     m <<= 1;
    // }
    // a = a ^ m;
    // cout << a;

    // method 3--> x is numerical value of a number, then
    // ~x = -(x+1) [ ~ is for bitwise complement ]
    // (x + 1) is due to the addition of 1 in 2’s complement conversion
    // To get (x + 1) apply negation once again. So, the final expression becomes (-(~x)).

    // int a;
    // cin>>a;
    // a=-(~a);
    // cout<<a;
    //
    //
    //

    //
    //
    //
    //
    //
    //
    //

    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    // $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ Multiply a given Integer with 3.5 $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
    // We can get x*3.5 by adding 2*x, x and x/2. To calculate 2*x, left shift x by 1 and to calculate x/2, right shift x by 1.
    //
    //
    // int a;
    // cin >> a;

    // int m= a + (a << 1) + (a >> 1);
    // cout<<m;
    //
    //
    //
    //
    //
    //
    //
    //

    //
    //
    //
    //
    //
    //
    //
    //
    //
    // ################################################### Turn off the rightmost set bit #########################################
    // Find the position of the right most 1 bit and left shift the mask that no. of times to change the 1 bit to zero..
    // 5->101  so mask will be 1
    // 12->1100 so mask will be 100
    // int a;
    // cin >> a;
    // int mask = 1;
    // while ((a & mask) == 0)

    // {
    //     mask = mask << 1;

    // }
    // int m = a ^ mask;
    // cout << m;
    //

    //

    //
    //
    //

    //     method-2Let the input number be n. n-1 would have all the bits flipped after the rightmost set bit (including the set bit). So, doing n&(n-1) would give us the required result.

    // So, now let us see how n – 1 is flipping all the bits to the right (including the rightmost set bit also) of the n.
    // Taking n = 12, so (n – 1) = 11,

    // n can be written like (n = (n – 1) + 1), so now we can think of this problem as Adding 1 to Any Number (refer this article for better understanding)
    // Binary representation of (n-1) = 11 = 1011, so now lets make n from (n-1), which can be done by adding a 1 to (n-1)
    // On adding 1 to any number X, all bits to the right of  rightmost 0 (including the rightmost zero) gets flipped
    // (n-1) = 1011

    // (n-1) + 1 = 1100 (all the bits to the right of rightmost zero (including rightmost zero) got flipped)
    // Since we have flipped the rightmost zero, so now, rightmost zero is now flipped to rightmost 1 (aka the rightmost set bit of n) and all bits before rightmost 0 are the same as before
    // X = 010 . . . . . 0 (rightmost zero) 111

    // int a;
    // cin >> a;

    // cout << (a & (a - 1));
    //
    //
    //
    //
    //

    //
    //
    //
    //

    //
    //
    //
    //

    //
    //
    //
    //
    //
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Program to find whether a given number is power of 2!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // int n;
    // cin>>n;
    // int cnt=0;
    // while (n>0)
    // {
    //     if((n & 1)==0){
    //         cnt++;
    //     }
    //     n=n>>1;

    // }
    // if (cnt==true)
    // {
    //    cout<<true;
    // }
    // else{
    //     cout<<false;
    // }

    // method 2->

    // int x;
    // cin >> x;
    // cout << (x && (!(x & (x - 1))));

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Find whether a given number is a power of 4 or not ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //     A number n is a power of 4 if the following conditions are met.
    // a) There is only one bit set in the binary representation of n (or n is a power of 2)
    // b) The count of zero bits before the (only) set bit is even.
    // For example 16 (10000) is the power of 4 because there is only one bit set and count of 0s before the set bit is 4 which is even.

    // int n;
    // cin >> n;
    // int count = 0;
    // if ((n && !(n & (n - 1))))
    // {

    //     while (n > 1)
    //     {
    //         count++;
    //         n = n >> 1;
    //     }
    // }

    // (count % 2 == 0) ? cout << true : cout << false;
    //

    //
    //
    //
    //
    //
    //
    //
    //
    //

    //

    //

    //

    //
    //
    //
    //
    //
    //
    //
    // &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& Compute modulus division by a power-of-2-number &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
    // For example if n = 6 (00..110) and d = 4(00..100). Last set bit in d is at position 3 (from right side). So we need to return last two bits of n as they are and other bits as 0, i.e., 00..010.
    // int a, b;
    // cin >> a >> b;
    // cout << (a & (b - 1)) << endl;
    // cout << a % b;

    //

    //

    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    // ==============------------------------------------Rotate bits of a number------------------------=============
    /* In n<<d, last d bits are 0. To
     put first 3 bits of n at
    last, do bitwise or of n<<d
    with n >>(INT_BITS - d) */
    /* In n<<d, last d bits are 0. To
     put first 3 bits of n at
    last, do bitwise or of n<<d
    with n >>(INT_BITS - d) */
    // int a, d;
    // cin >> a >> d;

    // cout << ((a << d) | (a >> (___int_size_t_h - d)));  //--->left rotation
    // cout<<endl;
    // cout<<((a>>d)|(a<<(___int_size_t_h-d))); //--->Right rotation

    // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@To count the number of ones in a binary representation of a number@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@2
    // int a;
    // cin >> a;
    // int count = 0;
    // while (a != 0)
    // {
    //     count++;
    //     a = a & (a - 1);
    // }
    // cout<<count;

    //
    //
    //
    //
    //
    //
    //
    //
    //
    //

    //

    //
    //
    //
    //
    //

    // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@2Generate all Possible subsets of a set {a,b,c}@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    // int n;
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    // for (int i = 0; i < (1 << n); i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (i & (1 << j))
    //         {
    //             cout << arr[j] << " ";
    //         }
    //     }
    //     cout << endl;
    // }

    //
    //

    //
    //

    //
    //
    //

    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ Efficient way to multiply with 7 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    // int a;
    // cin >> a;
    // cout << (a<<3)-a;

    //

    //
    //

    //

    //

    //
    //
    //

    //
    //

    //
    //
    //

    //

    //
    // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@Position of rightmost set bit@@@@@@@@@@@@@@@@@@@@@22
    // (n&~(n-1)) always return the binary number containing the rightmost set bit as 1.
    // if N = 12 (1100) then it will return 4 (100)

    //     int a;
    //     cin >> a;
    //     cout << log2(a & -a);

    // int a;
    // cin >> a;
    // int cnt = 0;

    // while (a != 0)
    // {
    //     if (a & 1)
    //     {
    //         cout << cnt;
    //         break;
    //     }
    //     cnt++;
    //     a >>= 1;
    // }
    // cout << cnt;

    //
    //

    //
    //

    //
    //

    //
    //
    //
    //
    //
    //
    //
    //
    // ##################################### Find position of the only set bit#################################
    // int n;
    // cin >> n;
    // if (!(n && (!(n & (n - 1)))))
    // {
    //     cout << -1;

    // }
    // else
    // {
    //     cout << log2(n & -n) + 1;
    // }

    //

    //

    //
    //

    //

    //
    //
    //
    //
    //
    //
    //

    //
    // @@@@@@@@@@@@@@@@@@@@@@@@@@@@ How to swap two numbers without using a temporary variable? @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    // int a,b;
    // cin>>a>>b;
    // a=a^b;
    // b=a^b;
    // a=a^b;
    // cout<<a<<" "<<b;

    //
    //
    //

    //

    //

    //
    //
    //
    //
    //
    // ==============================How to turn off a particular bit in a number? ==============================
    // int a, i;
    // cin >> a >> i;

    // int mask = 1 << i;

    // cout << (a ^ mask);
    // //

    //
    //

    //
    //
    //
    //
    //
    //
    //
    //

    //
    //
    //

    // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ Russian Peasant (Multiply two numbers using bitwise operators) @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //     Let the two given numbers be 'a' and 'b'
    // 1) Initialize result 'res' as 0.
    // 2) Do following while 'b' is greater than 0
    //    a) If 'b' is odd, add 'a' to 'res'
    //    b) Double 'a' and halve 'b'
    // 3) Return 'res'.

    // int a, b;
    // cin >> a >> b;
    // int res = 0;
    // while (b > 0)
    // {
    //     if (b & 1)
    //     {
    //         res = res + a;
    //     }
    //     a = a << 1;
    //     b = b >> 1;
    // }
    // cout<<res;

    //

    //
    //
    // /
    //
    //
    //
    //
    //
    //
    //
    //

    //
    //

    //
    //
    //

    // **************************************Swap two nibbles in a byte*********** ***********************

    // A nibble is a four-bit aggregation, or half an octet. There are two nibbles in a byte.
    // Given a byte, swap the two nibbles in it. For example 100 is be represented as 01100100 in a byte (or 8 bits). The two nibbles are (0110) and (0100). If we swap the two nibbles, we get 01000110 which is 70 in decimal.

    // Step 1: Take & of 00001111 with number to get right nibble i.e. 0b00001111 & N

    // Step 2: Take & of 11110000 with number to get left nibble i.e. 0b11110000 & N

    // Step 3: Left shift the right nibble obtained in step 1 by 4 positions to get it as left nibble in the final answer i.e. <<4

    // Step 4: Right shift the left nibble obtained in step 2 by 4 positions to get it as right nibble in final answer >>4
    //     unsigned short a;
    //     cin >> a;
    // int right=(a & 0b00001111);
    //     int left=(a & 0b11110000);
    //     cout<<((right<<4) | (left>>4));

    //
    //
    //
    //
    //

    //
    //

    // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^Find XOR of two number without using XOR operator^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    // int a;
    // int b;
    // cin >> a >> b;
    // int res = 0;
    // for (int i = 31; i >= 0; i--)
    // {
    //     bool b1 = a & (1 << i);
    //     bool b2 = b & (1 << i);

    //     bool XORBIT = (b1 & b2) ? 0 : (b1 | b2);
    //     res = res << 1;
    //     res = res | XORBIT;
    // }
    // cout << res;

    //
    //

    //
    //
    //
    //
    //
    //
    //
    //
    // /*\/*\/*\/*\/*\/*\/*\/*\/*\Write your own strcmp that ignores cases/*\/*\/*\/*\/*\/*\/*\/*

    //     char str1[50];
    //     char str2[50];
    //     gets(str1);
    //     gets(str2);
    // int i;
    //     for ( i = 0; (str1[i] && str2[i]); i++)
    //     {
    //         if ((str1[i] == str2[i]) || ((str1[i] ^32) == str2[i]))
    //         {
    //             continue;
    //         }
    //         else
    //         {
    //             break;
    //         }
    //     }

    //     if (str1[i] == str2[i])
    //     {
    //         cout << 0;
    //     }
    //     else if ((str1[i - 1] ^ 32) < (str2[i - 1] ^ 32))
    //     {
    //         cout << -1;
    //     }

    //     else
    //     {
    //         cout << 1;
    //     }
    //     
    //     
    //     
    //     
    //     

    //
    //
    //
    //
    //
    //

    //
    //
    //
    // <><><><><><><><><><><><><><><><><><><><>><>Check if two numbers are equal without using arithmetic and comparison operators<><><><<><><><><><><><><><<>
    int a;
    int b;
    cin >> a >> b;
    if (a ^ b)
    {
        cout << "not equal";
    }
    else
    {
       
        cout <<"equal";
    }

    return 0;
}