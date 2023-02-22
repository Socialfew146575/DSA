#include <bits/stdc++.h>
using namespace std;

void path1(string p,int r,int c){

    if(r==1&&c==1){
        cout<<p<<" ";
        return;
    }

    if(r>1){
        path1(p+"D",r-1,c);
    }
    if(c>1){
        path1(p+"R",r,c-1);
    }


}

void path2(string p,int r,int c,int row,int col){

    if(r==row-1&&c==col-1){
        cout<<p<<" ";
        return;
    }

    if(r<row-1){
        path2(p+"D",r+1,c,row,col);
    }
    if(c<col-1){
        path2(p+"R",r,c+1,row,col);
    }


}




int main(){
path1("",3,3);
cout<<endl;
path2("",0,0,3,3);
return 0;
}