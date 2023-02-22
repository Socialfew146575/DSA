#include <bits/stdc++.h>
using namespace std;
void solve(string str, string output, int index, vector<string> &ans)
{

    if (index >= str.length())
    {
        if (output.length() > 0)
        {
            ans.push_back(output);
        }

        return;
    }

    solve(str, output, index + 1, ans);

    output.push_back(str[index]);
    solve(str, output, index + 1, ans);
}

vector<string> subsequences(string str)
{

    vector<string> ans;
    string output = "";
    int index = 0;

    solve(str, output, index, ans);
    return ans;
}


// Approach 2

void subseq(string p,string s){
    if(s.length()==0){
        cout<<p<<" ";
        return;
    }

    char ch=s[0];

    subseq(p+ch,s.substr(1));
    subseq(p,s.substr(1));
}

int main()
{
    string set = "abc";
    vector<string> ans = subsequences(set);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    // using bit manipulation
    for (int i = 0; i < (1 << 3); i++)
    {cout<<"{";
        for (int j = 0; j < 3; j++)
        {   
            if (i & (1 << j))
            {
                cout << set[j];
            }
        }
        cout<<"},";
    }

    cout<<endl;

    subseq("","abc");

    cout<<endl;

   
}
