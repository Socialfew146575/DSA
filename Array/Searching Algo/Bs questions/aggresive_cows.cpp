#include <iostream>
using namespace std;
bool isPossible(int array[],int size,int cow,int mid){
    int cowCount=1;
    int lastPos=array[0];
    for (int i = 0; i < size; i++)
    {
        if (array[i]-lastPos >=mid)
        {
            cowCount++;
            if (cowCount==cow)
            {
                return true;
            }
            
            lastPos=array[i];
        }
        
    }
    return false;
}

int aggresive_cow(int array[],int size,int cow){


// Sorting
    int s=0;
    int e;
    int maxi=INT32_MIN;
    for (int i = 0; i < size; i++)
    {
        maxi=max(maxi,array[i]);
   
    }
    e=maxi;

    int mid;
    int ans=-1;
    while (s<=e)
    {   mid=s+(e-s)/2;
        if(isPossible(array,size,cow,mid)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    
    
return ans;
}

int main(){



return 0;
}