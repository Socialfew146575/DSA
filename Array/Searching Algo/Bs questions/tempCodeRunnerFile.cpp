#include <iostream>
#include<vector>
using namespace std;

 vector<int> twoSum(vector<int>& numbers, int target) {
        int s=0;
        int e=numbers.size()-1;
        vector<int>ans;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(numbers[mid]>target){
                e=mid-1;
            }else{
                for(int i=0;i<mid;i++){
                    if(numbers[i]+numbers[mid]==target){
                        ans.push_back(i);
                        ans.push_back(mid);
                    }
                    else{
                        s=mid+1;
                    }
                }
            }
        }
        return ans;
    }
int main(){
vector<int> numbers={2,7,11,15};
cout<<twoSum(numbers,9);
return 0;
}