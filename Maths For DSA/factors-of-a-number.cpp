#include <bits/stdc++.h>
using namespace std;

// Brute force => O(n)
void factors(int n)
{

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
}

// Optimized => 0(sqrt(n))
void factors2(int n)
{

    for (int i = 1; i <= sqrt(n); i++)

    {
        if (n % i == 0)
        {
            if (n / i == i)
            {
                cout << i << " ";
            }
            else
            {
                cout << i << " " << n / i << " ";
            }
        }
    }
}

// Both time and space complexity is O(sqrt(n))
void factors3(int n)
{
    vector<int> fact;
    for (int i = 1; i <= sqrt(n); i++)

    {
        if (n % i == 0)
        {
            if (n / i == i)
            {
                cout << i << " ";
            }
            else
            {
                cout << i << " ";
                fact.push_back(n / i);
            }
        }
    }

    
    for (int i = fact.size()-1; i>=0; i--)
    {
        cout<<fact[i]<<" ";
    }
}

int main()
{

    factors(20);
    cout << endl;
    factors2(36);
    cout << endl;
    factors3(36);

    return 0;
}