#include <bits/stdc++.h>
using namespace std;

int solve(string s, int k)
{

    int i = 0, j = 0;
    int n = s.length();
    int mx = INT_MIN;
    unordered_map<char, int> mp;

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
            mx = max(mx, count);

            j++;
        }
        else
        {

            while (mp.size() > k)
            {
                mp[s[i]]--;

                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }

            if (mp.size() == k)
            {
                int count = 0;
                for (auto i : mp)
                {
                    count += i.second;
                }
                mx = max(mx, count);
            }
            j++;
        }


    }
    return mx;
}

    int main()
    {

        string s = "aabacbebebe";
        int k = 3;

        cout << solve(s, k) << endl;

        string a="aaaa";
        cout << solve(a, 1) << endl;


        return 0;
    }