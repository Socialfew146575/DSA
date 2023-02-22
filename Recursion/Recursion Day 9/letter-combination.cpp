#include <bits/stdc++.h>
using namespace std;
void solve(string digits,string output,vector<string>&ans,int index,string mapping[]){
    // basecase
    if(index>=digits.length()){
        ans.push_back(output);
        return;
    }

    int number=digits[index]-'0';
    string value=mapping[number];

    for (int i = 0; i < value.length(); i++)
    {
        output.push_back(value[i]);
        solve(digits,output,ans,index+1,mapping);
        output.pop_back();

    }
    
}

 vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.length()==0){
            return ans;
        }
        string output;
        int index=0;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,output,ans,index,mapping);
        return ans;
    }


void pad(string p,string up,string mapping[]){
    if(up.length()==0){
        cout<<p<<" ";
        return;
    }

    int digit=up[0]-'0';
    string value=mapping[digit];
    for (int i = 0; i < value.length(); i++)
    {
        char ch=value[i];
        pad(p+ch,up.substr(1),mapping);
    }
    


}

int countPad(string p,string up,string mapping[]){
    if(up.length()==0){
       
        return 1;
    }
    int count=0;
    int digit=up[0]-'0';
    string value=mapping[digit];
    for (int i = 0; i < value.length(); i++)
    {
        char ch=value[i];
       count+= countPad(p+ch,up.substr(1),mapping);
    }

    return count;


}
int main(){

    vector<string>ans=letterCombinations("23");
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
    cout<<endl;
       string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    pad("","23",mapping);

    cout<<endl<<countPad("","23",mapping);
return 0;
}