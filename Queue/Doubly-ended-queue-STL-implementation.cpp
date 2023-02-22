#include <bits/stdc++.h>
using namespace std;

int main()
{

    deque<int> d;

    d.push_back(6);
    d.push_back(7);
    d.push_back(8);
    d.push_back(9);
    d.push_back(10);

    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;

    d.push_front(5);
    d.push_front(4);
    d.push_front(3);
    d.push_front(2);
    d.push_front(1);

    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;

    d.pop_back();
    d.pop_front();
    d.pop_back();
    d.pop_front();
  

      for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;


cout<<"Size of dequeue is :"<<d.size()<<endl;
cout<<"is dequeue d empty? :"<<d.empty()<<endl;

cout<<"Element at front in dequeue "<<d.front()<<endl;
cout<<"Element at back in dequeue "<<d.back()<<endl;

    return 0;
}