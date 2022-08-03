#include<iostream>
using namespace std;
// For floor value
int square_root(int n){
  int array[n+1];
  for (int i = 0; i <= n; i++) {
      array[i]=i;
      }
      int s=0;
      int e=n;
      int ans=-1;
      int mid;

      while (s<=e) {
        mid=s+(e-s)/2;

        if (mid*mid==n) {

          return mid;

        }
        else if(mid*mid>n){
          e=mid-1;

        }
        else{
          ans=mid;
          s=mid+1;
        }
      }
    return ans;
}

// With Point after ans
double morePrecision(int n,int precision,int tempsol){
  double factor=1;
  double ans=tempsol;
  for (int i = 0; i < precision; i++) {
    factor=factor/10;
    for (double j = ans; j*j<n; j=j+factor) {

      ans=j;
    }
  }
  return ans;

}


int main(){
int n;
cin>>n;
int tempsol=square_root(n);
cout<<"Answer is "<<morePrecision(n,3,tempsol);

  return 0;

}
