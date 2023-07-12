#include<bits/stdc++.h>
using namespace std;
// *********************************************************** WITH (N) SPACE COMPLEXITY *****************************************************************
// class Solution{
// public:

// 	void rearrange(int arr[], int n) {
//     vector<int> pos,neg;
//     for(int i=0;i<n;i++){
//         if(arr[i]<0){
//             neg.push_back(arr[i]);
//         }
//         else{
//             pos.push_back(arr[i]);
//         }
//     }
//     int i=0;
//     int j=0;
//     int k=0;
//     while(i<pos.size() && j<neg.size()){
//         arr[k++]=pos[j++];
//         arr[k++]=neg[i++];
//     }
//     while(j<pos.size()){
//      arr[k++]=pos[j++];   
//     }
//     while(i<neg.size()){
//      arr[k++]=neg[i++];   
//     }
    
// 	}
// };



/*

The idea is to process the array from left to right. While processing, find the first out-of-place element in the remaining unprocessed array. An element is out of place if it is negative and at odd index (0-based index), or if it is positive and at even index (0-based index). Once we find an out-of-place element, we find the first element after it with an opposite sign. We right rotate the subarray between these two elements (including these two).

Illustration:

Let the array be arr[] = { -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 }

First iteration: 

{ -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 } , -2 appears on odd index position and is out of place.
We will look for the first element that appears with an opposite sign
{ -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 } => perform rotation of subarray between this two elements
{ -5, 5, -2, 2, 4, 7, 1, 8, 0, -8 }
Second iteration: 

{ -5, 5, -2, 2, 4, 7, 1, 8, 0, -8 } , 4 is out of place.
{ -5, 5, -2, 2, 4, 7, 1, 8, 0, -8 } =>-8 is of different sign 
{ -5, 5, -2, 2, -8, 4, 7, 1, 8, 0 } => after performing right rotation between 4 to -8
Algorithm:
We will maintain a variable to mark if the element is in its correct position or not. Let the variable be outofplace. Initially, it is -1.

We will iterate over the array
If outofplace is -1, we will check if the current index is out of place.
If the current index is out of place we will update the outofplace with the index value.
Else we will keep the value as it is.
If the outofplace is not -1, we will search for the next index which has a different sign than that of the value that is present in outofplace position.
Now we will pass this two positions to right rotate our array.
Update the value of outofplace by 2 unit.
Following is the implementation of the above idea.  



#include <assert.h>
#include <iostream>
using namespace std;
  
// Utility function to right rotate all elements between
// [outofplace, cur]
void rightrotate(int arr[], int n, int outofplace, int cur)
{
    char tmp = arr[cur];
    for (int i = cur; i > outofplace; i--)
        arr[i] = arr[i - 1];
    arr[outofplace] = tmp;
}
  
void rearrange(int arr[], int n)
{
    int outofplace = -1;
  
    for (int index = 0; index < n; index++) {
        if (outofplace >= 0) {
            // find the item which must be moved into the
            // out-of-place entry if out-of-place entry is
            // positive and current entry is negative OR if
            // out-of-place entry is negative and current
            // entry is negative then right rotate
            //
            // [...-3, -4, -5, 6...] -->   [...6, -3, -4,
            // -5...]
            //      ^                          ^
            //      |                          |
            //     outofplace      -->      outofplace
            //
            if (((arr[index] >= 0) && (arr[outofplace] < 0))
                || ((arr[index] < 0)
                    && (arr[outofplace] >= 0))) {
                rightrotate(arr, n, outofplace, index);
  
                // the new out-of-place entry is now 2 steps
                // ahead
                if (index - outofplace >= 2)
                    outofplace = outofplace + 2;
                else
                    outofplace = -1;
            }
        }
  
        // if no entry has been flagged out-of-place
        if (outofplace == -1) {
            // check if current entry is out-of-place
            if (((arr[index] >= 0) && (!(index & 0x01)))
                || ((arr[index] < 0) && (index & 0x01))) {
                outofplace = index;
            }
        }
    }
}
  
// A utility function to print an array 'arr[]' of size 'n'
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
  
// Driver code
int main()
{
  
    int arr[] = { -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 };
    int n = sizeof(arr) / sizeof(arr[0]);
  
    cout << "Given array is \n";
    printArray(arr, n);
  
    rearrange(arr, n);
  
    cout << "Rearranged array is \n";
    printArray(arr, n);
  
    return 0;
}
Output
Given array is 
-5 -2 5 2 4 7 1 8 0 -8 
Rearranged array is 
-5 5 -2 2 -8 4 7 1 8 0 
Time Complexity: O(N*N), as we are using a loop to traverse N times and calling function to right rotate each time which will cost O (N).
Auxiliary Space: O(1).

*/


