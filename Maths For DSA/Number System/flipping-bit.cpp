#include <bits/stdc++.h>
using namespace std;
// Given an n x n binary matrix image, flip the image horizontally, then invert it, and return the resulting image.

// To flip an image horizontally means that each row of the image is reversed.

// For example, flipping [1,1,0] horizontally results in [0,1,1].
// To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.

// For example, inverting [0,1,1] results in [1,0,0].

vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image)
{
    for (int i = 0; i < image.size(); i++)
    {
        int s = 0;
        int e = image[0].size() - 1;
        while (s <= e)
        {

            int temp = image[i][e] ^ 1;
            image[i][e] = image[i][s] ^ 1;
            image[i][s] = temp;

            s++;
            e--;
        }
    }

    return image;
}

int main()
{

    vector<vector<int>> v = {{1, 1, 0},
                             {1, 0, 1},
                             {0, 0, 0}};

    vector<vector<int>> ans = flipAndInvertImage(v);

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}