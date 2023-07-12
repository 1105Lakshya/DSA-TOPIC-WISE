#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int linear_search(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(key==arr[i])
        return i;
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key ;
    cout<<"Enter the value u want to search"<<endl;
    cin>>key;
    cout<<linear_search(arr,n,key);
    
    return 0;
}