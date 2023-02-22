#include <bits/stdc++.h>
using namespace std;

void allPaths(string p,vector<vector<bool>>maze,int r,int c){

    if(r==maze.size()-1&&c==maze[0].size()-1){
        cout<<p<<" ";
        return;
    }

    if(maze[r][c]==false){
        return;
    }

    maze[r][c]=false;
    if(r<maze.size()-1){

        allPaths(p+'D',maze,r+1,c);
    }
    if(c<maze[0].size()-1){
        allPaths(p+'R',maze,r,c+1);
    }
    if(r>0){
        allPaths(p+'U',maze,r-1,c);
    }
    if(c>0){
        allPaths(p+'L',maze,r,c-1);
    }

    maze[r][c]=true;





}

int main(){
    vector<vector<bool>>maze{{true,true,true},{true,true,true},{true,true,true}};
    allPaths("",maze,0,0);
return 0;
}