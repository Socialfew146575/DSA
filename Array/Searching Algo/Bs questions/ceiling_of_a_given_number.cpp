#include<bits/stdc++.h>
using namespace std;
int ceiling(int array[],int size,int target){
  int s=0;
  int e=size-1;
  int ans=0;
  while(s<=e){
    int mid=s+(e-s)/2;
    if (array[mid]>=target) {
      ans=array[mid];
      e=mid-1;
    }
    else{
      s=mid+1;
    }
    }
    return ans;
}
int main(){

int array[7]={2 , 3, 5 ,9,14,16,18};
cout<<ceiling(array,7,14);

  return 0;
}
