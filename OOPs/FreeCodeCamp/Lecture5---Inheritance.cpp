#include <bits/stdc++.h>
using namespace std;

// Abstract Class
class AbstractEmployee
{
    virtual void AskForPromotion() = 0;
};

class Employee : AbstractEmployee
{

private:
    string Company;
    int Age;

protected:
    string Name;

public:
    // Setter
    void setName(string name)
    {
        Name = name;
    }
    void setCompany(string company)
    {
        Company = company;
    }
    void setAge(int age)
    {
        Age = age;
    }

    // Getter
    string getName()
    {
        return Name;
    }

    string getCompany()
    {
        return Company;
    }
    int getAge()
    {
        return Age;
    }
    void Intro()
    {
        cout << " Name : " << Name << endl;
        cout << " Company : " << Company << endl;
        cout << " Age : " << Age << endl;
    }

    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }

    void AskForPromotion()
    {
        if (Age > 30)
        {
            cout << Name << " got promoted.\n";
        }
        else
        {
            cout << Name << ", sorry NO promotion for you.\n";
        }
    }
};

// Inheritance
// Base class--Employee
// Derived class--Developer
class Developer : public Employee
{
public:
    string FavProgrammingLanguage;

    Developer(string name, string company, int age, string favProgrammingLanguage) : Employee(name, company, age)
    {
        FavProgrammingLanguage = favProgrammingLanguage;
    }

    void FixBug()
    {

        cout << getName() << " fixed bug using " << FavProgrammingLanguage << ".\n";
        // No Error---Protected Access Modifer
        // cout << Name<< " fixed bug using " << FavProgrammingLanguage << ".\n";

        // cout<<Company;---Error--Private Access Modifier
    }
};

class Teacher : public Employee
{
public:
    string Subject;
    void PrepareLesson()
    {
        cout << Name << " is preparing " << Subject << " lesson.\n";
    }

    Teacher(string name, string company, int age, string subject) : Employee(name, company, age)
    {
        Subject = subject;
    }
};

int main()
{

    Developer d = Developer("D1", "C1", 25, "C++");
    d.Intro();
    d.FixBug();
    d.AskForPromotion();

    Teacher t = Teacher("T1", "C2", 31, "History");
    t.Intro();
    t.PrepareLesson();
    t.AskForPromotion();

    return 0;
}