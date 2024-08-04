#include<iostream>
using namespace std;
void sortOne(int arr[],int n){
    int left=0,right=n-1;
    while(left<=right){
        while(arr[left]==0 && left<right){
            left++;
        }
        while(arr[right]==1 && left<right){
            right--;
        }
        //agar yaha pe pahucha hai mere bhai matlab arr[i]=1 hai or arr[j]=0
        if(left<right){
        swap(arr[left],arr[right]);
        left++;
        right--;
        }
    }
    
}
int main(){
    int n;
    cout<<"Enter N"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter zeros and ones"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sortOne(arr, n);

    for(int i=0;i<n;i++){
cout<<arr[i]<<" ";
    }
    return 0;
}