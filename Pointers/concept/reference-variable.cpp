#include <bits/stdc++.h>
using namespace std;

void update1(int n)
{
    n++;
}

void update2(int &n)
{
    n++;
}

int main()
{

    // int i = 5;

    // // create a reference variable
    // int &j = i;

    // cout << i<<" "<<j << endl;
    // i++;
    // cout << i<<" "<<j << endl;
    // j++;
    // cout << i<<" "<<j << endl;



    cout<<"Call by value"<<endl;
    int n = 5;
    cout << "before " << n << endl;

    update1(n);
    cout << "After " << n << endl;
  

  cout<<"Call by reference"<<endl;
    cout << "before " << n << endl;

    update2(n);
    cout << "After " << n << endl;

    return 0;
}