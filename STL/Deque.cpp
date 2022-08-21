#include <iostream>
#include <deque>
using namespace std;

int main()
{

    deque<int> d;
    d.push_back(0);  // Introducing an element at the end of the deque.
    d.push_front(1); // Introducing an element at the starting of the deque.
    d.push_front(2);
    d.push_front(3);
    d.push_front(4);

    cout << "element at 0th index:- " << d.at(0) << endl;

    cout << "First element:- " << d.front() << endl;
    cout << "Last element:- " << d.back() << endl;

    cout << "Whether it is empty or not:- " << d.empty() << endl;

    cout << "Before Erasing:- " << endl;
    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }

    cout << endl;

    d.erase(d.begin(), d.end() - 3); // Delete elements within the given range...

    cout << "after Erasing" << endl;
    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;

    
    d.pop_front(); // deleting first element
    d.pop_back();  // deleting last element
    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
    d.clear();

    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;

    cout << endl;

    return 0;
}