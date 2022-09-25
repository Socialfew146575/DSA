#include <bits/stdc++.h>
using namespace std;


int resetBit(int n,int i){
    int mask=1<<i-1;

    int c_mask= ~mask;
    

    // return n^mask;
    return n&c_mask;
}





int main(){
    cout<<resetBit(86,5);
return 0;
}