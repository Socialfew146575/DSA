#include <bits/stdc++.h>
using namespace std;


// Abstract Class
class AbstractEmployee{
       virtual void AskForPromotion()=0;
};


class Employee:AbstractEmployee
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



    void AskForPromotion(){
        if(Age>30){
            cout<<Name<<" got promoted.\n";
        }
        else{
            cout<<Name<<", sorry NO promotion for you.\n";
        }
    }
};

int main()
{
    Employee emp1 = Employee("A", "C1", 31);

    Employee emp2 = Employee("B", "C2", 23);

    emp1.AskForPromotion();
    emp2.AskForPromotion();

   
    


    return 0;
}