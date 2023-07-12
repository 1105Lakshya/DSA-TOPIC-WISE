//************************SUM OF ALL SUBARRAY****************************************************
#include<iostream>
using namespace std;

int main(){
    int sum=0;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        int current=0;
        for(int j=i;j<n;j++){
            current+=arr[j];
            cout<<current<<endl;
        }
    }
    cout<<"The sum of all the subarrays is:"<<sum<<endl;
    return 0;
}