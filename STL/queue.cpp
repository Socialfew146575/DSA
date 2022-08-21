#include <iostream>
#include <queue>
using namespace std;

int main()
{

    queue<string> q;

    q.push("I");
    q.push("Love");
    q.push("You");

    cout << "First element:- " << q.front() << endl;
    q.pop();
    cout << "First element:- " << q.front() << endl;

    cout<<"Size:- "<<q.size();
    
    return 0;
}