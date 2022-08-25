#include <iostream>
using namespace std;

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

int getLength(char name[])
{

    int i;
    for (i = 0; name[i] != '\0';)
    {
        i++;
    }
    return i;
}

bool check_palindrome(char name[])
{

    int i = 0;
    int j = getLength(name) - 1;

    while (i < j)
    {
        if (toLower(name[i]) != toLower(name[j]))
        {
            return false;
        }
        else
        {
            i++;
            j--;
        }
    }

    return true;
}

void reverse(char name[])
{

    int i = 0;
    int j = getLength(name) - 1;

    while (i < j)
    {
        swap(name[i], name[j]);
        i++, j--;
    }
}

int main()
{

    char name[20];
    cout << "Enter Your Name " << endl;
    cin >> name;

    cout << "Your name is ";
    cout << name << endl;

    cout << "Length of name is " << getLength(name) << endl;

    cout << "Reversing the string" << endl;
    reverse(name);
    cout << name << endl;

    cout << "Checking Whether string is palindrome or not:-" << endl;
    cout << check_palindrome(name) << endl;

    return 0;
}