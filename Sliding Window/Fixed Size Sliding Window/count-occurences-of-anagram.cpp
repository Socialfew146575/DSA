#include <bits/stdc++.h>
using namespace std;

void solve1(string a, string b)
{

    int n = a.length();
    int k = b.length();

    int i = 0, j = 0;
    int count = 0;

    sort(b.begin(), b.end());
    string ans = "";
    while (j < n)
    {
        if (ans.length() < k)
        {
            ans += a[j];
        }

        if (j - i + 1 < k)
        {
            j++;
        }
        else
        {

            string r = ans;
            sort(r.begin(), r.end());
            if (r == b)
                count++;

            i++;
            j++;

            for (int i = 0; i < k - 1; i++)
            {
                ans[i] = ans[i + 1];
            }
            ans[k - 1] = a[j];
        }
    }

    cout << count << endl;
}

void solve2(string a, string b)
{

    int n = a.length();
    int k = b.length();

    unordered_map<char, int> mp;

    for (auto ch : b)
    {
        mp[ch]++;
    }

    int ans = 0;
    int count = mp.size();

    int i = 0, j = 0;

    while (j < n)
    {
        if (mp.find(a[j]) != mp.end())
        {
            mp[a[j]]--;

            if (mp[a[j]] == 0)
                count--;
        }

        if (j - i + 1 < k)
        {
            j++;
        }

        else
        {

            if (count == 0)
              
            ans++;

            if (mp.find(a[i]) != mp.end())
            {
                mp[a[i]]++;
                if (mp[a[i]] == 1)
                    count++;
            }

            i++;
            j++;
        }
    }

    cout << ans << endl;
}

int main()
{

    string a, b;

    cin >> a >> b;

    solve1(a, b);
    solve2(a, b);

    return 0;
}