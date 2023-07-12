#include<bits/stdc++.h>
using namespace std;


int getSum(int arr[], int n, int K){
    deque<int > maxi;
    deque<int>  mini;

    for(int i=0;i<K;i++){
        while(!maxi.empty()&& arr[maxi.back()]< arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty()&& arr[mini.back()]> arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans=0;
    ans+=arr[maxi.front()]+arr[mini.front()];
    for(int i=K ;i<n;i++){

        // next window
        

        //removal
        if(!maxi.empty() &&  i-maxi.front()>= K){
            maxi.pop_front();
        }
        if(!mini.empty() &&  i-mini.front()>=K){
            mini.pop_front();
        }

        //addition
        while(!maxi.empty()&& arr[maxi.back()]< arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty()&& arr[mini.back()]> arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
        ans+=arr[maxi.front()]+arr[mini.front()];

    }

    return ans;
}


int main(){
    int n;
    cin>>n;
    int window_size;
    cin>>window_size;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=getSum(arr, n ,window_size);
    cout<<"THE SUM ISSSSSS:"<< sum<<endl;
    return 0;
}