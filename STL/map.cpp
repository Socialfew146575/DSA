#include <iostream>
#include <map>
using namespace std;

int main()
{

    map<int, string> m;

    m[1] = "Arun";
    m[2] = "Lohani";
    m.insert({3, "CSE"});
    cout << "Finding 3->" << m.count(3) << endl;

    cout << "BEFORE ERASE" << endl;
    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }

    m.erase(2);
    cout << "AFTER ERASE" << endl;
    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }


    auto it=m.find(3);

    for(auto i=it;i!=m.end();i++){
        cout<<(*i).first<<endl;
    }
    return 0;
}