#include<iostream>
#include<vector>
using namespace std;
//   peak in a mountain

//                   89
//             76        54
//          54               2 
//        5                     2 
//      4                           0
//    3 
//  2 
// 1
    class Solution {
    int binarySearch(vector<int>& arr)
{   int n=arr.size();
    int s = 0;
    int e = n - 1;
      int mid=s+(e-s)/2;
    while (s < e)            //jaise hi start equal to end hogga loop se bahr challa jaayegaa apna 
    {   if(arr[mid+1]>arr[mid]){
        s=mid+1;
          }
     else 
         e=mid;                 //  mid minus one isliye ni kiyyyaa kyukiiii fir end answer pe point krne ke bajjaye pichhe challa jatta
     mid=s+(e-s)/2;
    }

    return e;   //s or e anything will work
}
public:
    int peakIndexInMountainArray(vector<int>& arr) {
    return binarySearch(arr);
    }
    };
int main(){
    
    return 0;
}