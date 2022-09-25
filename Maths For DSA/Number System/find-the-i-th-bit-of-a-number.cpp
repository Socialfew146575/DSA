#include <bits/stdc++.h>
using namespace std;

bool findBit(int n,int i){

    int mask=1<<i-1;

    return n&mask;

}



int main(){
cout<<findBit(182,5);

return 0;
}