
#include <bits/stdc++.h>
using namespace std;

bool redundantBrackets(string &s)
{

    stack<int> st;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else
        {
            if (ch == ')')
            {
                bool isRedundant = true;

                while (st.top() != '(')
                {

                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isRedundant = false;
                    }
                    st.pop();
                }

                if (isRedundant == true)
                {
                    return true;
                }
                st.pop();
            }
        }
    }

    return false;
}

int main()
{

    string s = "((a+b))";

    cout << redundantBrackets(s) << endl;

    string a = "(a+(b*c))";

    cout << redundantBrackets(a) << endl;

    string b = "((a+b+c))";
    cout << redundantBrackets(b) << endl;

    return 0;
}