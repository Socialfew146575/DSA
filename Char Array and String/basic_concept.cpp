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
char toUpper(char ch)
{
    char temp;
    if (ch >= 'A' && ch <= 'Z')
    {
        return ch;
    }

    else
    {
        temp = ch + 'A' - 'a';
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

    cout << "To lower case a string:-" << endl;
    for (int i = 0; name[i] != '\0'; i++)
    {
        name[i] = toLower(name[i]);
    }

      cout << name << endl;

      
    cout << "To Upper case a string:-" << endl;
    for (int i = 0; name[i] != '\0'; i++)
    {
        name[i] = toUpper(name[i]);
    }

    cout << name << endl;

    cout << "Reversing the string" << endl;
    reverse(name);
    cout << name << endl;

    string name2 = "ab\0cde";
    cout << name2;
    return 0;
}