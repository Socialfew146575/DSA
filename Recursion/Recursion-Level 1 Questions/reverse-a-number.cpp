#include <bits/stdc++.h>
using namespace std;

int reverse(int n,int sum)
{

    if (n == 0)
    {
        return sum;
    }

    int rem=n%10;
    sum=sum*10+rem;

    return reverse(n/10,sum);



   
}

int main()
{   
    cout<<reverse(1234,0);

    return 0;
}