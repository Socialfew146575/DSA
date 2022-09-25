#include <bits/stdc++.h>
using namespace std;


// global variable
int score = 15;

void a(int &i)
{
    cout << score << " in a" << endl;
    
    cout << i << endl;
}

void b(int &i)
{
    cout << score << " in b" << endl;
    cout << i << endl;
    score++;
    a(i);
}

int main()
{

    cout << score << " in main" << endl;
    int i = 5;
    b(i);

    return 0;
}