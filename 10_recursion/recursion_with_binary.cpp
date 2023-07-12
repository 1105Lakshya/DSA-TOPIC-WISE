#include<iostream>
using namespace std;
int BinarySearch(int arr[],int s,int e,int k){
    if(s>e){
        return -1;
    }
    int mid=s+(e-s)/2;

    if(arr[mid]<k){
        return BinarySearch(arr,mid+1,e,k);
    }
    else if(arr[mid]>k){
        return BinarySearch(arr,s,mid-1,k);
    }
    else{
        return mid;
    }

    return -1;
}




int main(){
    int arr[]={2,4,6,10,14,16};
    int n=6;
    int key=18;
    cout<<"Present or not"<<BinarySearch( arr, 0, n-1, key);

    return 0;
}