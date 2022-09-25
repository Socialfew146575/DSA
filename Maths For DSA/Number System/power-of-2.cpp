#include <bits/stdc++.h>
using namespace std;

bool powerof2(int n)
{

    return !(n & n - 1);
}

int main()
{   
    cout<<powerof2(128);

    return 0;
}