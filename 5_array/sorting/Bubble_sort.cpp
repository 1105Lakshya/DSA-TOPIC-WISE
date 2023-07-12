// LOGIC:  REPEATEDLY SWAP TWO ADJACENT ELEMENTS IF THEY ARE IN WRONG ORDER
// number of passes required for n elements is n-1

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
        int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // for(int i=0;i<n-1;i++){
    //     for(int j=0;j<n-i-1;j++){
    //         if(arr[j]>arr[j+1]){
    //             int temp=arr[j];
    //         arr[j]=arr[j+1];
    //         arr[j+1]=temp;
    //         }
    //     }
    // }
    // OR
    int counter =1;
    while(counter <n){
        for(int i=0;i<n-counter;i++){
                if(arr[i+1]<arr[i]){
            int temp =arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
        }
    counter++;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
    return 0;
}