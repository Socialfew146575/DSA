#include<bits/stdc++.h>
using namespace std;
int floor(int array[],int size,int target){
  int s=0;
  int e=size-1;
  int ans=-1;
  while (s<=e) {
    int mid=s+(e-s)/2;
    if (array[mid]==target) {
      return array[mid];
    }else if (array[mid]<target) {
      ans=array[mid];
      s=mid+1;
    }
    else{
      e=mid-1;
    }
  }
  return ans;
}
int main(){
int arr[]={2,3,5,9,14,16,18};
cout<<floor(arr,7,32);
  return 0;
}
