#include <bits/stdc++.h>
using namespace std;
int countPermutations(string p, string up)
{
    if (up.length() == 0)
    {   
        return 1;
    }
    int count=0;
    char ch = up[0];
    for (int i = 0; i <= p.length(); i++)
    {
        string f = p.substr(0,i);
    

        string s = p.substr(i,p.length());
   

      

       count+= countPermutations(f + ch + s, up.substr(1));
    }
    return count;
}

int main(){
  string s = "abc";
        cout<<countPermutations("",s);
return 0;
}