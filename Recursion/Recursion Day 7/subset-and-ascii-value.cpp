#include <bits/stdc++.h>
using namespace std;


void subseq(string p,string s){
    if(s.length()==0){
        cout<<p<<" ";
        return;
    }

    char ch=s[0];

    subseq(p+ch,s.substr(1));
    subseq(p,s.substr(1));
    subseq(p+to_string(int(ch)),s.substr(1));
}


int main(){
    subseq(" ","abc");
return 0;
}