#include<iostream>
using namespace std;

int main(){
        int n;
    cout<<"Enter the number of days"<<endl;
    cin>>n;
    int a[n];
    cout<<"enter the number of visitors"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int j=1;
    int max=a[0];
    int record =0;
    if(a[0]>a[1]){
        record++;
    }
    
    while(j<n-1){
        if(a[j+1]<a[j] && a[j]>max){
            record++;
        }
            if(a[j]>max)
            max=a[j];
        j++;
    }
    if(a[n-1]>max)
    record++;

    cout<<"The number of record breaking days are "<<record<<endl;
    
    return 0; 
}