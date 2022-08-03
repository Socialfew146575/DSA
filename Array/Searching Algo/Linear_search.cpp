#include <bits/stdc++.h>
using namespace std;
int even_digit(int array[],int size){
    int count=0;
    for (int i = 0; i < size; i++)
    {
        int digit=log10(array[i])+1;
        if(digit%2==0){
            count++;
        }
    }
    return count;
    
}
void max_min(int array[],int size){
    int max=array[0];
    int min=array[0];
    for (int  i = 1; i < size; i++)
    {   if (max<array[i])
    {
        max=array[i];
    }
    if (min>array[i])
    {
       min=array[i];
    }
    
    
        
    }

    cout<<"Max is "<<max<<endl;
    cout<<"Min is "<<min<<endl;

    
}
bool search_in_range(int array[],int size,int key,int s,int e){
    for (int i = s; i <= e; i++)
    {
        if (array[i]==key)
        {
            return true;
        }
        
        
    }

    return false;
    
    
}
bool linear_search(int array[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == key)
        {
            return 1;
        }
    }
    return 0;
}
void inputArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int array[1000];
    inputArray(array, n);
    // printArray(array, n);
    // int key;
    // cin >> key;
    // int s,e;
    // cin>>s>>e;

    // cout << "Is key present in the array?" << endl;
    // if (linear_search(array, n, key)

    // )
    // {
    //     cout << "Key is present";
    // }
    // else
    // {
    //     cout << "Key is not present";
    // }   
    
    //  if (search_in_range(array, n, key,s,e)

    // )
    // {
    //     cout << "Key is present between index " <<s <<" and " <<e;
    // }
    // else
    // {
    //     cout << "Key is not present is not present between the index "<< s <<" and "<< e;
    // }

    // max_min(array,n);
    cout<<even_digit(array,n);
    return 0;
}