#include <bits/stdc++.h>
using namespace std;

void solve(string s, int k)
{
    int n = s.length();
    int i = 0, j = 0;
    unordered_map<char, int> mp;

    int mx = INT_MIN;

    while (j < n)
    {
        mp[s[j]]++;

        if (mp.size() < k)
        {
            j++;
        }

        else if (mp.size() == k)
        {
            int count = 0;
            for (auto i : mp)
            {
                count += i.second;
            }
            mx = max(count, mx);
            j++;
        }

        else
        {

            while (mp.size() > k)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }

            if (mp.size() == k)
            {
                int count = 0;
                for (auto i : mp)
                {
                    count += i.second;
                }
                mx = max(count, mx);
            }
            j++;
        }
    }
    cout<<mx<<endl;
}

int main()
{
    string toy = "abaccab";

    solve(toy, 2);
    return 0;
}