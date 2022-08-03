#include<iostream>
using namespace std;

bool isPossible(int array[],int size,int k,int mid){
  int studentCount=1;
  int pageSum=0;
  for (int i = 0; i < size; i++) {
      if (pageSum+array[i] <= mid) {
        pageSum+=array[i];
      }
      else{
        studentCount++;
        if ((studentCount > k) || (array[i]>mid)) {
          return false;
        }

        pageSum=array[i];
      }
  }
  return true;
}

int book_allocation(int array[],int size,int k){
  int s=0;
  int e=0;
  for (int i = 0;i < size;i++) {
    s=max(s,array[i]);
    e=array[i]+e;

  }
  int ans=-1;
  int mid;
  while (s<e) {
    mid=s+(e-s)/2;
    if(isPossible(array,size,k,mid)) {
      ans=mid;
      e=mid-1;
    }
      else{
        s=mid+1;
      }
    }


  return ans;
}

int main(){
  int array[]={7,2,5,10,8};
cout<<book_allocation(array,5,2);



  return 0;
}
