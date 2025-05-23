


















//WATCH STRIVER VIDEO NO WAY YOU CAN DO THIS ON YOUR OWN




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=0;
        int high=arr.size()-1;

        while(low<=high){
            int mid=(low+high)/2;

            int missing=arr[mid]-(mid+1);

            if(missing<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high+1+k;
        //return low+k;
    }
};
  

// class Solution {
// public:
//     int findKthPositive(vector<int>& arr, int k) {
//         int n=arr.size();

//         for(int i=0;i<n;i++){
//             if(arr[i]<=k)k++;
//             else return k;
//         }

//         return k;
//     }
// };

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    
    return 0;
}