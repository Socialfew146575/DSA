#include <bits/stdc++.h>
using namespace std;

// A man want to reach his home by taking one step at a time.Help him do this recursivey...


void reachHome(int src, int dest)
{

    // Base Case
    cout << "->"<<" ";
    if (src == dest)
    {

        cout << "Home" << endl;
        return;
    }

    // Processing
    src++;

    // Recursive Call
    reachHome(src, dest);
}

int main()
{

    int dest = 10;
    int src = 1;

    cout << "Man";
    reachHome(src, dest);

    return 0;
}