#include <bits/stdc++.h>
using namespace std;

bool matches(char top, char ch)
{

    if (top == '[' && ch == ']')
        return true;
    if (top == '{' && ch == '}')
        return true;
    if (top == '(' && ch == ')')
        return true;

    return false;
}

bool isValidParenthesis(string exp)
{

    stack<char> s;

    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];

        if (ch == '[' || ch == '{' || ch == '(')
        {

            s.push(ch);
        }
        else
        {

            if (!s.empty())
            {
                char top = s.top();

                if (matches(top, ch))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }

            else
            {
                return false;
            }
        }
    }
    if (s.empty())
        return true;
}

int main()
{

    string exp = "[()]{}{[()()]()}";

    cout << isValidParenthesis(exp) << endl;

    string exp2 = "[(])";
    cout << isValidParenthesis(exp2) << endl;

    return 0;
}