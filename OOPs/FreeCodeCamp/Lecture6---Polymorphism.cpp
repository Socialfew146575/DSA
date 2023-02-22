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

    virtual void Work(){
        cout<<Name<<" is checking email, task backlog, performing tasks...\n";
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
     void Work(){
        cout<<Name<<" is writing "<<FavProgrammingLanguage<<" code"<<".\n";
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

    void Work(){
        cout<<Name<<" is teaching "<<Subject<<".\n";
    }
};

int main()
{

    // The most common use of polymorphism is when a parent class reference is used to refer to a child class object..


    Employee e=Employee("E1","C2",35);

    Developer d = Developer("D1", "C1", 25, "C++");

    Teacher t = Teacher("T1", "C2", 31, "History");

    e.Work();
    d.Work();
    t.Work();

    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;

    Employee* e1=&d;
    Employee* e2=&t;

    e1->Work();
    e2->Work();


    return 0;
}