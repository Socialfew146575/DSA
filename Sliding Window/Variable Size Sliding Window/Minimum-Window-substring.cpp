#include <bits/stdc++.h>
using namespace std;

void solve(string s, string t)
{

    int n = s.length();
    unordered_map<char, int> mp;
    int i = 0, j = 0;

    for (auto i : t)
    {
        mp[i]++;
    }
    int count = mp.size();
    int mn = INT_MAX;
    int start = 0;

    while (j < n)
    {
        if (mp.find(s[j]) != mp.end())
        {
            mp[s[j]]--;

            if (mp[s[j]] == 0)
                count--;
        }

        if (count > 0)
        {
            j++;
        }
        else
        {

            if (mn > j - i + 1)
            {
                mn = j - i + 1;
                start = i;
            }

            while (count == 0)
            {
                if (mp.find(s[i]) == mp.end())
                {
                    i++;
                    if (mn > j - i + 1)
                    {
                        mn = j - i + 1;
                        start = i;
                    }
                }

                else
                {

                    mp[s[i]]++;
                    if (mp[s[i]] > 0)
                    {
                        count++;
                        i++;
                    }
                    else
                    {
                        i++;
                        if (mn > j - i + 1)
                        {
                            mn = j - i + 1;
                            start = i;
                        }
                    }
                }
            }
            j++;
        }
    }

    cout << mn << endl;
    string ans=s.substr(start, mn);
    cout<<ans<<endl;
}

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";

    solve(s, t);
    return 0;
}