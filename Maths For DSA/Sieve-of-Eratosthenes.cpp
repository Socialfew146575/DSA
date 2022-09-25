#include <bits/stdc++.h>
using namespace std;

//************************ Given an integer n, return the number of prime numbers that are strictly less than n.*****************************



//*************** SIEVE OF ERATOSTHENES**********
int countPrimes(int n)
{
    int count = 0;
    vector<bool> prime(n, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            count++;

            for (int j = 2 * i; j < n; j = j + i)
            {
                prime[j] = 0;
            }
        }
    }
    return count;
}

// void sieve(long long n)
// {

//     vector<bool> isPrime(n + 1, true);
//     for (long long i=2; i*i< n; i++)
//     {
//         if (isPrime[i])
//         {
           

//             for (int j = i * i; j <= n; j += i)
//             {
//                 isPrime[j] = false;
//             }
//         }
//     }

//     for (long long i = 2; i < n+1; i++)
//     {
//         if(isPrime[i]){
//             cout<<i<<" ";
//         }
//     }
    
// }



int main()
{
    int n;
    cin >> n;

    cout << "Number of primes strictly less than " << n << " are:- " << countPrimes(n);

    

    return 0;
}