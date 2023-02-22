#include <bits/stdc++.h>
using namespace std;

vector<int> bruteForce(vector<vector<int>> person)
{

    vector<int> ans;

    for (int i = 0; i < person.size(); i++)
    {
        bool celeb = true;
        for (int j = 0; j < person[i].size(); j++)
        {
            if (person[i][j] != 0)
            {
                celeb = false;
                break;
            }
        }

        if (celeb)
        {

            for (int j = 0; j < person.size(); j++)
            {
                if (j == i)
                    continue;

                if (person[j][i] != 1)
                {
                    celeb = false;
                    break;
                }
            }
        }

        if (celeb)
        {
            ans.push_back(i);
        }
    }
    if(ans.size()==0) return {-1};
    return ans;
}

bool knows(vector<vector<int>> person, int a, int b)
{

    if (person[a][b] == 1)
        return true;
    else
        return false;
}

int celebrity(vector<vector<int>> person)
{

    stack<int> s;

    for (int i = 0; i < person.size(); i++)
    {
        s.push(i);
    }

    while (s.size() != 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if (knows(person, a, b))
        {

            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }

    bool rowCheck = true;

    for (int i = 0; i < person.size(); i++)
    {
        if (person[s.top()][i] != 0)
        {
            rowCheck = false;
            break;
        }
    }

    bool colCheck = true;

    for (int i = 0; i < person[s.top()].size(); i++)
    {
        if (i == s.top())
            continue;
        if (person[i][s.top()] != 1)
        {
            colCheck = false;
            break;
        }
    }

    if (colCheck && rowCheck)
        return s.top();
    else
        return -1;
}

int main()
{

    vector<vector<int>> person = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};

    vector<int> ans = bruteForce(person);

    cout << "The celebrities are ";

    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "The celebrities are " << celebrity(person);
    cout << endl;
    vector<vector<int>> per = {{0, 1}, {1, 0}};

    vector<int> res = bruteForce(per);

    cout << "The celebrities are ";

    for (int i : res)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "The celebrities are " << celebrity(per);
    return 0;
}