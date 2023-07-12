#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter N"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxSum=INT_MIN;
    int currsum=0;
    for(int i=0;i<n;i++){
        currsum+=arr[i];
        if(currsum<0)
        currsum=0;
        maxSum=max(maxSum,currsum);
    }
    cout<<maxSum;
    return 0;
}