#include <iostream>
using namespace std;

bool valid(char ch)
{

    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {

        return 1;
    }

    return 0;
}

char toLower(char ch)
{
    char temp;
    if (ch >= 'a' && ch <= 'z')
    {
        return ch;
    }
    else
    {
        temp = ch - 'A' + 'a';
    }
    return temp;
}

bool isPalindrome(string s)
{

    int i = 0;
    int j = s.length() - 1;
    bool check = true;

    while (i <= j)
    {

     
        if(!(valid(s[i])))
        {
            i++;
        }

        else if (!(valid(s[j])))
        {
            j--;
        }

        
       
        else if (toLower(s[i]) !=  toLower(s[j]))
        {

            return false;
        }


        else
        {
            i++;
            j--;
        }
    }

    return check;
}

int main()
{

    cout<<isPalindrome("A man, a plan, a canal -- Panama");
    return 0;
}