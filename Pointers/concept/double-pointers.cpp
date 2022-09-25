#include <bits/stdc++.h>
using namespace std;

void update(int **p2)
{

    // p2 = p2 + 1;
    // *p2 = *p2 + 1;
    **p2 = **p2 + 1;
}

int main()
{

    int i = 5;

    int *ptr = &i;
    int **ptr2 = &ptr;

    cout << "printing i " << i << endl;
    cout << "printing address of i " << &i << endl;
    cout << endl;
    cout << "printing ptr " << ptr << endl;
    cout << "printing address of ptr " << &ptr << endl;
    cout << "printing value stored at the address stored in ptr1 " << *ptr << endl;
    cout << endl;
    cout << "printing ptr2 " << ptr2 << endl;
    cout << "printing address of ptr2 " << &ptr2 << endl;
    cout << "printing address stored at the address stored in ptr2 " << *ptr2 << endl;
    cout << "printing value stored at the address stored in the ptr2 " << **ptr2 << endl;

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    update(ptr2);

    cout << "printing i " << i << endl;
    cout << "printing address of i " << &i << endl;
    cout << endl;
    cout << "printing ptr " << ptr << endl;
    cout << "printing address of ptr " << &ptr << endl;
    cout << "printing value stored at the address stored in ptr1 " << *ptr << endl;
    cout << endl;
    cout << "printing ptr2 " << ptr2 << endl;
    cout << "printing address of ptr2 " << &ptr2 << endl;
    cout << "printing address stored at the address stored in ptr2 " << *ptr2 << endl;
    cout << "printing value stored at the address stored in the ptr2 " << **ptr2 << endl;

    cout << endl;
    
    return 0;
}