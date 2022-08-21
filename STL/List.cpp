#include <iostream>
#include <list>
using namespace std;

int main()
{

    list<int> l;

    l.push_back(0);
    l.push_front(1);
    l.push_back(2);
    l.push_front(3);

    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "First element:- " << l.front() << endl;
    cout << "Last element:- " << l.back() << endl;

    // at method do not work in list..

    l.erase(l.begin());
    // delete element one by one;
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;

    l.pop_back();
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;
    l.pop_front();
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;

    // Copying all the elements of a list to a new list.
    list<int> k(l);
    for (int i : k)
    {
        cout << i << " ";
    }
    cout << endl;



    list<int> j = {1, 2, 4};
    for (int i : j)
    {
        cout << i << " ";
    }
    cout << endl;

    list<int>h(5,143);
            for (int i:h)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}