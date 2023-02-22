#include <bits/stdc++.h>
using namespace std;

class Employee
{

private:
    string Name;
    string Company;
    int Age;

public:
    // Setter
    void setName(string name){
        Name=name;
    }
     void setCompany(string company){
        Company=company;
    }
     void setAge(int age){
        Age=age;
    }
    


    // Getter
    string getName(){
        return Name;
    }

    string getCompany(){
        return Company;
    }
    int getAge(){
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
};

int main()
{
    Employee emp1 = Employee("A", "C1", 20);
    emp1.Intro();
    cout<<endl;

    Employee emp2 = Employee("B", "C2", 23);
    emp2.Intro();
    cout<<endl;

    // emp1.Name="C"; -->Access not possible
    emp1.setName("C");

    // cout<<emp1.Name; 
    cout<<emp1.getName()<<"\n";
    


    return 0;
}