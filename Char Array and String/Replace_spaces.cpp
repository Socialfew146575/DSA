#include <iostream>
#include<string>
using namespace std;

void replace_spaces(string s){

    int i=0;
    int n=s.length();
    while (i<n)
    {   
        if(s[i]==' '){
            s[i]='@';
            s.insert(i+1,"40");
        }
        i++;
    }

    cout<<s;


}

int main(){

    string s="Geeks For Geeks";
    cout<<"Before replacing spaces"<<endl;
    cout<<s<<endl;
    cout<<"After replacing spaces"<<endl;
    replace_spaces(s);
   

return 0;
}