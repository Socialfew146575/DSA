#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{

    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);
    v.push_back(9);

    cout << "Binary_search->" << binary_search(v.begin(), v.end(), 7) << endl;

    cout << "Lower Bound->" << lower_bound(v.begin(), v.end(), 5) - v.begin() << endl;
    cout << "Upper Bound->" << upper_bound(v.begin(), v.end(), 5) - v.begin() << endl;

    int a = 3;
    int b = 5;
    cout << "max ->" << max(a, b) << endl;
    cout << "min ->" << min(a, b) << endl;

    swap(a, b);

    cout << "a->" << a << endl;
    cout << "b->" << b << endl;

    string abcd = "abcd";
    reverse(abcd.begin(), abcd.end());

    cout << "REVERSED STRING->" << abcd << endl;

    rotate(v.begin(), v.begin() + 1, v.end());
    cout << "After rotate" << endl;
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    sort(v.begin(), v.end());
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}