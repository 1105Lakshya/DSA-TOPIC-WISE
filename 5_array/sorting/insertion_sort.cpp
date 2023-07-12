// logic:inert an element from unsorted array to its correct psotion in sorted array



#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of elements u want in array"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<n;i++){
        int temp =arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
        for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }    

    return 0;
}

// worst case time complexcity is squar(n)
// best case time complexcity is n