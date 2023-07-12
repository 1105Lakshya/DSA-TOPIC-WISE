// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n;
//     cout<<"enter the length of array "<<endl;
//     cin>>n;
//     cout<<"Enter the numberr in array"<<endl;
//     int arr[n];
//     for(int i=0; i<n;i++){
//         cin>>arr[i];
//     }
//     int max_num=arr[0];
//     int min_num=arr[0];
//     for(int i=0;i<n;i++){
//         if(max_num<arr[i])
//         max_num=arr[i];
        
//     }
//     for(int i=0;i<n;i++){
//         if(min_num>arr[i])
//         min_num=arr[i];
        
//     }
//     cout<<"Max term in the array is :"<<max_num<<endl;
//     cout<<"Min term in the array is :"<<min_num<<endl;

//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"enter the length of array "<<endl;
    cin>>n;
    cout<<"Enter the numberr in array"<<endl;
    int arr[n];
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    int max_num=INT_MIN;
    int min_num=INT_MAX;
    for(int i=0;i<n;i++){
        max_num=max(max_num,arr[i]);
        min_num=min(min_num,arr[i]);
        
    }
    
    cout<<"Max term in the array is :"<<max_num<<endl;
    cout<<"Min term in the array is :"<<min_num<<endl;

    return 0;
}
