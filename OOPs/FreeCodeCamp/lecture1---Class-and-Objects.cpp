#include <bits/stdc++.h>
using namespace std;

// Class
class Employee
{ // Access Modifiers===>
  //   1.private(default)
  //   2.public
  //   3.protected
public:
    string Name;
    string Company;
    int Age;

    void Intro()
    {
        cout << "My Name is " << Name << endl;
        cout << "I work at " << Company << endl;
        cout << "My age is " << Age << endl;
    }
};

int main()
{
    // Object--Instance of Class
    Employee emp1;

    // Attributes
    emp1.Name = "Arun";
    emp1.Company = "GBPIET";
    emp1.Age = 19;

    // Behaviour or Methods
    emp1.Intro();

    return 0;
}