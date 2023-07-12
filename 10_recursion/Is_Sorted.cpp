#include<iostream>
using namespace std;
bool IsSorted(int arr[],int size){
    if(size==0 || size==1){
        return true;
    }
    else{
        if(arr[0]>arr[1]){
            return false; 
        }else{
            return IsSorted(arr+1,size-1);
        }
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool check= IsSorted(arr,n);
    if(check)
    cout<<"Yes it is sorted"<<endl;
    else{
        cout<<"No it is not sorted"<<endl;
    }

    return 0;
}