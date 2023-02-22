#include <bits/stdc++.h>
using namespace std;

void solve(string s)
{

    int n = s.length();
    unordered_map<char, int> mp;
    int i = 0, j = 0;
    int count = 0;

    while (j < n)
    {
        mp[s[j]]++;

        if (mp.size() == j - i + 1)
        {
          
            count = max(count, j - i + 1);
            j++;
        }

        else
        {

            while (mp.size() < j - i + 1)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }

            if (mp.size() == j - i + 1)
            {
                cout << endl;
                count = max(j - i + 1, count);
            }
            j++;
        }
    }
    cout<<count<<endl;
}

int main()
{

    string s = "pwwkew";

    solve(s);

    return 0;
}