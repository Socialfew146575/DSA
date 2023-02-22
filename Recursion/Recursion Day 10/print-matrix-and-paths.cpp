#include <bits/stdc++.h>
using namespace std;

void pathMatrix(string p, vector<vector<bool>> maze, int r, int c, vector<vector<int>> path, int step)
{
  
    if (r == maze.size() - 1 && c == maze[0].size() - 1)
    {   
        path[r][c]=step;
        cout<<endl;
        for (int i = 0; i < path.size(); i++)
        {
            for (int j = 0; j < path[0].size(); j++)
            {
                cout << path[i][j] << " ";
            }

            cout << endl;
        }

        cout << p << " ";
        cout<<endl;
        cout<<endl;

        return;
    }

    

     if (maze[r][c] == false)
    {

        return;
    }

    maze[r][c] = false;
    path[r][c] = step;

   

    if (r < maze.size() - 1)
    {   

        pathMatrix(p + 'D', maze, r + 1, c, path, step + 1);
    }
    if (c < maze[0].size() - 1)
    {

        pathMatrix(p + 'R', maze, r , c+1, path, step + 1);
    }
 
    if (r>0)
    {

        pathMatrix(p + 'U', maze, r - 1, c, path, step + 1);
    }
    if (c>0)
    {

        pathMatrix(p + 'L', maze, r, c-1, path, step + 1);
    }
    maze[r][c]=true;
    path[r][c]=0;
  
    
}

int main()
{   vector<vector<bool>>maze{{true,true,true},{true,true,true},{true,true,true}};
    vector<vector<int>>path{{0,0,0},{0,0,0},{0,0,0}};
    pathMatrix("",maze,0,0,path,1);

    return 0;
}