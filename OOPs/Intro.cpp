#include <bits/stdc++.h>
// #include "Hero.cpp"    ### To create class in another file and include it with the main program ###
using namespace std;

// ### Empty Class is of size 1 ###

class Hero
{

    // properties
private:
    int health;
    char level;
    char *name;

public:
    static int timeToComplete;
    // Constructor with no parameter

    Hero()
    {
        cout << "Constructor is called" << endl;
        name = new char[100];
    }

    // **** Parameterized Constructor ****

    Hero(int health, char level)
    {

        // this is a pointer which stores the address of the current object...
        this->health = health;
        this->level = level;
    }

    // **** Copy Constructor ****

    Hero(Hero &temp)
    {
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;
        this->health = temp.health;
        this->level = temp.level;
    }

    // Setter

    void setHealth(int h)
    {
        health = h;
    }

    void setLevel(char l)
    {
        level = l;
    }

    void setName(char name[])
    {

        strcpy(this->name, name);
    }
    // Getter

    int getHealth()
    {
        return health;
    }

    char getLevel()
    {
        return level;
    }

  

    void print()
    {
        cout << endl;
        cout << "[";
        cout << "Name : " << this->name << "\t";
        cout << "Level : " << this->level << "\t";
        cout << "Health : " << this->health << " ]";
        cout << endl;
    }

    static int random()
    {
        // this pointer is not available in static function as this is a pointer of object
        // it can only access static member

        return timeToComplete;
    }

    ~Hero()
    {

        cout << "Destructor is called " << endl;
    }
};

int Hero::timeToComplete = 5;

int main()
{

    // ##################################################################

    // // creation of object

    // Hero h1;

    // // cout<<"size : "<<sizeof(h1)<<endl;

    // // h1.health=70;
    // // h1.level='A';

    // // cout<<"health is "<<h1.health<<endl;
    // // cout<<"level is "<<h1.level<<endl;

    // h1.setHealth(70);
    // h1.setLevel('A');

    // cout<<"Health is "<<h1.getHealth()<<endl;
    // cout<<"Level is "<<h1.getLevel()<<endl;

    // ################################################################

    // **** Static Allocation ****
    /*
    Hero a;
    a.setHealth(70);
    a.setLevel('A');

    cout << "Health of Hero a is " << a.getHealth() << endl;
    cout << "Level of Hero a is " << a.getLevel() << endl
         << endl;

    // ****  Dynamic Allocation ****

    Hero *b = new Hero;
    (*b).setHealth(100);
    (*b).setLevel('B');

    cout << "Health of Hero b is " << (*b).getHealth() << endl;
    cout << "Level of Hero b is " << (*b).getLevel() << endl
         << endl;

    Hero *c = new Hero;

    c->setHealth(50);
    c->setLevel('C');

    cout << "Health of Hero c is " << c->getHealth() << endl;
    cout << "Level of Hero c is " << c->getLevel() << endl
         << endl;

    */

    //  ##################################################################

    // When an object is created , a constructor is called automatically...

    // ***** Constructor with no parameter ****

    // Statically created object
    // Hero H1;

    // Dynamically created object
    // Hero *H2=new Hero();

    // **** Parameterized Constructor ****

    // Hero H1 = Hero(67, 'A');
    // H1.print();
    // Hero *H2 = new Hero(89, 'B');
    // H2->print();

    // // **** Copy Constructor ****

    // Hero a(70, 'A');
    // a.print();

    // Hero b(a);
    // b.print();

    // ##########################################################################

    // **** Shallow Copy ****

    // Hero hero1;
    // hero1.setHealth(13);
    // hero1.setLevel('D');
    // char name[5]="Paul";
    // hero1.setName(name);
    // hero1.print();

    // // Use default copy constructor

    // Hero hero2=Hero(hero1);
    // hero2.print();

    // char name1[5]="Arun";
    // hero1.setName(name1);
    // hero1.print();
    // hero2.print();

    // **** Deep Copy ****

    //  Hero hero1;
    // hero1.setHealth(13);
    // hero1.setLevel('D');
    // char name[5]="Paul";
    // hero1.setName(name);
    // hero1.print();

    // // Use user Built copy constructor

    // Hero hero2(hero1);
    // hero2.print();

    // char name1[5]="Arun";
    // hero1.setName(name1);
    // hero1.print();
    // hero2.print();

    // ########################################################################

    // ***** Copy Assignment Operator *****
    // Hero hero1;
    // hero1.setHealth(13);
    // hero1.setLevel('D');
    // char name[5] = "Paul";
    // hero1.setName(name);

    // Hero hero2;
    // hero2.setHealth(4554);
    // hero2.setLevel('h');
    // char name1[4] = "Lee";
    // hero2.setName(name1);

    // hero1.print();
    // hero2.print();

    // hero1 = hero2;

    // hero1.print();
    // hero2.print();

    // #####################################################################################

    // ***** Destructor ****

    // For static destructor is called automatically
    /*
        Hero a;


        // For dynamic allocation destructor have to be called manually

        Hero *b=new Hero;
        delete b;

    */

    // ############################################################################################

    // **** Static variable - creates data member that belongs to class and can be called without creating an object

    // cout << Hero::timeToComplete << endl;

    // Hero a;
    // cout<<a.timeToComplete<<endl;

    // **** Static Function
    cout << Hero::random() << endl;

    return 0;
}