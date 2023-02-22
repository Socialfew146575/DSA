#include <bits/stdc++.h>
using namespace std;

class Employee
{
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

    // Constructor
    Employee(string name, string company, int age)
    {
        this->Name = name;
        this->Company = company;
        this->Age = age;
    }
};

int main()
{

    Employee emp = Employee("Arun", "TCS", 20);
    emp.Intro();

    return 0;
}