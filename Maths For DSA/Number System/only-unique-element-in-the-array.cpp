

#include <bits/stdc++.h>
using namespace std;

int uniqueElement(int array[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans ^= array[i];
    }

    return ans;
}

int main()
{
    int array[9] = {2, 3, 4, 1, 2, 1, 3, 6, 4};
    cout << uniqueElement(array, 9);
    return 0;
}