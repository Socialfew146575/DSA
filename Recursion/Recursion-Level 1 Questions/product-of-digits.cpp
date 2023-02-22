#include <bits/stdc++.h>
using namespace std;

int productOfDigits(int n){

    if(n==0){
        return 1;
    }

    return n%10*productOfDigits(n/10);


}


int main(){

    cout<<productOfDigits(1234);
return 0;
}