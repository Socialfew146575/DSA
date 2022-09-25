#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*
        int nums = 5;

        cout << nums << endl;





        // address of Operator ====> &

        cout << &nums << endl;






        // pointers

        int *ptr = &nums;

        cout << "Address is :" << ptr << endl; //=====> &nums

        cout << "Value is :" << *ptr << endl; //=====> nums

        cout << "Size of integer is " << sizeof(nums) << endl;

        cout << "Size of pointer is " << sizeof(ptr) << endl;







        // pointer to int is created, and pointing to some garbage address
        // Bad practise
        int *p;
        cout << *p << endl;








        Null Pointer

        int *ptr = 0;

        cout << *ptr << endl;








        int i = 5;

        int *p = 0;
        p = &i;

        cout << p << endl;
        cout << *p << endl;
    */

    // int num = 5;
    // int a = num;
    // cout<<" before "<<num<<endl;
    // a++;//==>No impact on num

    // cout<<"after " << num << endl;

    // int num=5;
    // int *ptr=&num;

    // cout<<"before "<<num<<endl;
    // (*ptr)++;//===>Impact on num

    // cout<<"after"<<num<<endl;

    // Copying a pointer

    // int num = 10;
    // int *p = &num;

    // int *q = p;

    // cout << p << " - " << q << endl;
    // cout << *p << " - " << *q << endl;

    // Pointer Arithmetic
    int i = 3;
    int *t = &i;

    // cout << (*t)++ << endl;

    cout<<"before "<<t<<endl;
    t=t+1;

    cout<<"after "<<t<<endl;


    

    return 0;
}