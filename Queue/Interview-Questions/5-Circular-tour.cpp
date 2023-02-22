#include <bits/stdc++.h>
using namespace std;

void solve1(int *petrol, int *distance, int n)
{

    for (int i = 0; i < n; i++)
    {
        int start = i;
        int balance = 0;
        bool tour = true;
        for (int j = start; j < n; j++)
        {
            balance = petrol[j] - distance[j] + balance;
            if (balance < 0)
            {
                tour = false;
                break;
            }
        }

        if (tour)
        {

            for (int j = 0; j < start; j++)
            {
                balance = petrol[j] - distance[j] + balance;
                if (balance < 0)
                {
                    tour = false;
                    break;
                }
            }
        }

        if (tour)
        {
            cout << i << " ";
            break;
        }
    }
}

int circularTour(int *petrol, int *distance, int n)
{

    int deficit = 0, balance = 0;

    int start = 0;

    for (int i = 0; i < n; i++)
    {
        balance += petrol[i] - distance[i];
        if (balance < 0)
        {   
            deficit += balance;
            start = i + 1;
            balance=0;
        }
    }

    if (deficit + balance >= 0)
    {
        return start;
    }
    else
    {
        return -1;
    }
}

int main()
{

    int n1 = 4;
    int petrol1[n1] = {4, 6, 7, 4};
    int distance1[n1] = {6, 5, 3, 5};

    solve1(petrol1, distance1, n1);
    cout<<circularTour(petrol1,distance1,n1);
    cout<<endl;
    int n2 = 5;
    int petrol2[n2] = {1, 2, 3, 4, 5};
    int distance2[n2] = {3, 4, 5, 1, 2};

    solve1(petrol2, distance2, n2);
    cout<<circularTour(petrol2,distance2,n2);

    return 0;
}