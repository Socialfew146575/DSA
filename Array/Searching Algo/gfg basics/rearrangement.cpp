
#include <bits/stdc++.h>
using namespace std;
//<--------------------------------------------- Rearrange an array such that arr[i] = i-------------------------------------->

// void rearrange(int ar[],int n){
//     int i, j, temp;

//     // Iterate over the array
//     for (i = 0; i < n; i++)
//     {
//         for (j = 0; j < n; j++)
//         {
//             // Check is any ar[j]
//             // exists such that
//             // ar[j] is equal to i
//             if (ar[j] == i) {
//                 temp = ar[j];
//                 ar[j] = ar[i];
//                 ar[i] = temp;
//                 break;
//             }
//         }
//     }

//     // Iterate over array
//     for (i = 0; i < n; i++)
//     {
//         // If not present
//         if (ar[i] != i)
//         {
//             ar[i] = -1;
//         }
//     }

//     // Print the output
//     cout << "Array after Rearranging" << endl;
//     for (i = 0; i < n; i++) {
//         cout << ar[i] << " ";
//     }
// }

// <--------------------------------------------------Write a program to reverse an array or string---------------------------------------->
// void reverse(int arr[],int size){
//     int i=0;
//     int j=size-1;
//     while (i<=j)
//     {
//         swap(arr[i],arr[j]);
//         i++;
//         j--;
//     }

//     for (int i = 0; i < size; i++)
//     { cout<<arr[i]<<" ";

//     }

// }

//   <---------------------------------------Rearrange array such that arr[i] >= arr[j] if i is even and arr[i]<=arr[j] if i is odd and j < i-------------------------------->
// void rearrange(int array[],int size){
//     int b[size];
//     for (int i = 0; i < size; i++)
//     {
//         b[i]=array[i];
//     }
//     sort(b,b+size);
//     int p=0;
//     int q=size-1;
//     for (int i = size-1; i >=0; i--)
//     {
//         if(i%2==0){
//             array[i]=b[p];
//             p++;
//         }
//         else{
//             array[i]=b[q];
//             q--;
//         }

//     }

//     for (int i = 0; i < size; i++)
//     {
//         cout<<array[i]<<" ";
//     }

// }

//    <--------------------------------------------- Rearrange positive and negative numbers in O(n) time and O(1) extra space--------------------------------------------------->
// Below process is about O(nlogn)...
// revisit when quicksort is learnt
// void rearrange(int array[], int size)
// {
//     int b[size];
//     for (int i = 0; i < size; i++)
//     {
//         b[i] = array[i];
//     }

//     sort(b, b + size);
//     int p = 0;
//     int q = size - 1;
//     for (int i = 0; i < size; i++)
//     {
//         if (i % 2 == 0)
//         {
//             array[i] = b[q];
//             q--;
//         }

//         else
//         {
//             array[i] = b[p];
//             p++;
//         }
//     }

//     for (int i = 0; i < size; i++)
//     {
//         cout<<array[i] << " ";
//     }
// }

int main()
{

    //  int arr[10] = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};

    //  rearrange(arr,10);
    //  cout<<endl;
    //  int a[]= {19, 7, 0, 3, 18, 15, 12, 6, 1, 8,
    //               11, 10, 9, 5, 13, 16, 2, 14, 17, 4};
    //  rearrange(a,20);

    // int arr[] = {4, 5, 1, 2};
    // reverse(arr,4);

    // int arr[] = {1, 2, 3};
    // reverse(arr,3);

    // int arr[] = {1, 2, 3, 4, 5, 6, 7};
    // rearrange(arr, 7);
    //    int arr[]= {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    //    rearrange(arr,9);
    // int arr[] = {-1, -2, -3, -4, -5, -6, 7, 8, 9};
    // rearrange(arr, 9);

    return 0;
}