#include<iostream>
using namespace std;
//                                               BRUTE FORCE APPROACH
// bool pairsum(int arr[],int n,int k ){
//     for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             if(arr[i]+arr[j]==k){
//                 cout<<i<<" "<<j<<endl;
//             }
//         }
//     }
// }
//array should be sorted for optimised approach
bool pairsum(int arr[],int n,int k ){
    int low =0;
    int high=n-1;
    while(low<high){
        if(arr[low]+arr[high]==k){
            cout<<low<<" "<<high<<endl;
            return true;
        }
        else if(arr[low]+arr[high]>k){
            high--;
        }
        else if(arr[low]+arr[high]<k){
            low++;
        }
    }
return false;
}


int main(){
    
    return 0;
}


//constant space solution

/*


class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
    sort(arr,arr+n);
    int count_pair=0;
    int i=0;
    int j=n-1;
    while(i<j){
        if(arr[i]+arr[j]<k)
        i++;
        else if(arr[i]+arr[j]>k)
        j--;
        else{
            if(arr[i]!=arr[j]){
            int count_i=1;
            int count_j=1;
            while(i<j  && arr[i]==arr[i+1]){
                count_i++;
                i++;
            }
            while( i<j     && arr[j]==arr[j-1]){
                count_j++;
                j--;
            }
            i++;j--;
            count_pair+=count_i*count_j;
        }
        else{
            int count=j-i+1;
            count_pair+=count*(count-1)/2;
        }
        }
    }
    return count_pair;
    }
};


*/




// big O of n space and time complexity

/*

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        int ans=0;
    unordered_map<int,int> count;
    for(int i=0;i<n;i++){
        int val=k-arr[i];
        if(count[val]){
            ans+=count[val];
        }
        count[arr[i]]++;
    }
    
    return ans;
    }
};


*/