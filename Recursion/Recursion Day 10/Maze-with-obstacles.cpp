#include <bits/stdc++.h>
using namespace std;

void pathRestrictions(string p,vector<vector<bool>>maze,int r,int c){

    if(r==maze.size()-1&&c==maze[0].size()-1){
        cout<<p<<" ";
        return;
    }

    if(maze[r][c]==false){
        return;
    }

    if(r<maze.size()-1){
        pathRestrictions(p+'D',maze,r+1,c);
    }
    if(c<maze[0].size()-1){
        pathRestrictions(p+'R',maze,r,c+1);
    }


}

int main(){

    vector<vector<bool>>maze{{true,true,true},{true,false,true},{true,true,true}};

    pathRestrictions("",maze,0,0);
return 0;
}