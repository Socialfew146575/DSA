#include <bits\stdc++.h>
using namespace std;


char max_occur(string s){

    vector<int> maxi(26,0);

    for (int i = 0; i < s.length(); i++)
    {      
        int index;
        if(s[i]>='A'&&s[i]<='Z'){
            index=s[i]-'A';
        }
        else{
            index=s[i]-'a';
        }

        maxi[index]++;

        
    }
    int m=-1,ans=0;
    for (int i = 0; i < 26; i++)
    {   if(m<maxi[i]){

            ans=i;
            m=maxi[i];
    }
        
    }

    return 'a'+ans;
  
 



}
int main(){

        cout<<max_occur("testsample");

return 0;
}