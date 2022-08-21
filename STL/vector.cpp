#include <iostream>
#include<vector>
using namespace std;

int main(){


vector<int> v;
// Capacity the memory allocated to the vector.
cout<<"Capacity:- "<<v.capacity()<<endl;

v.push_back(1);


cout<<"Capacity:- "<<v.capacity()<<endl;

v.push_back(2);

cout<<"Capacity:- "<<v.capacity()<<endl;

// It doubles its memory when there is no extra memory for the storage of the new element.
v.push_back(3);

cout<<"Capacity:- "<<v.capacity()<<endl;


// Size is the number of elements in the vector.

cout<<"Size:- "<<v.size()<<endl;



cout<<"Element at 2nd index:- "<<v.at(2)<<endl;

cout<<"First Element:- "<<v.front()<<endl;
cout<<"Last Element:- "<<v.back()<<endl;


cout<<"Before Pop"<<endl;

for (int i = 0; i < v.size(); i++)
{
    cout<<v[i]<<" ";
}
cout<<endl;
v.pop_back();

cout<<"After Pop"<<endl;

for (int i = 0; i < v.size(); i++)
{
    cout<<v[i]<<" ";
}
cout<<endl;


cout<<"Before Clearing, size:- "<<v.size()<<endl;

v.clear();

cout<<"after Clearing, size:- "<<v.size()<<endl;


vector <int> a(5,1);// a={1,1,1,1,1}
for (int i = 0; i < a.size(); i++)
{
    cout<<a[i]<<" ";
}
cout<<endl;
// Creating a vector which have same element as of vector a...
vector<int> copy(a);

for (int i = 0; i < copy.size(); i++)
{
    cout<<copy[i]<<" ";
}

cout<<endl;



cout<<endl;






return 0;
}