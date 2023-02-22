#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>arr,int k){
    int n=arr.size();
    int i=0;
    int j=0;
    int sum=0;
    
    
    
    int mx=INT_MIN;

    while(j<n){
       
      sum+=arr[j];

      if(j-i+1<k){
        j++;
      }
      else{

        mx=max(mx,sum);
        sum-=arr[i];
        i++;
        j++;


      }

    }

    return mx;


}

int main(){

vector<int>arr={100,200,300,400};
int k=2;

cout<<solve(arr,k)<<endl;

return 0;
}