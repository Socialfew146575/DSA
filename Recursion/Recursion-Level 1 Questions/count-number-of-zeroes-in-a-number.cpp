#include <bits/stdc++.h>
using namespace std;

int countZeroes(int n, int count)
{

    if (n == 0)
    {

        return count;
    }

    if (n % 10 == 0)
    {
        count++;
    }
   
    
        return countZeroes(n / 10, count);

}

int main()
{
    cout << countZeroes(302040,0);
    return 0;
}