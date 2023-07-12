#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the num"<<endl;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    const int N = 1e5;
    int idx[N];
    for (int i=0;i<N;i++){ 
    idx[i]=-1;
    }
    int minIdx=INT_MAX;
    for(int i=0;i<n;i++){
        if(idx[a[i]]!= -1){
            minIdx=min(minIdx,idx[a[i]]);
        }
        else{
            idx[a[i]]=i;
        }

    }
if(minIdx==INT_MAX)
cout<<-1;
else
cout<<minIdx;
    return 0;
}