#include<bits/stdc++.h>
using namespace std;



bool isPossible(int arr[],long long n,long long m,long long mid){
	long long sum=0;
	for(long long  i=0;i<n;i++){
		if(arr[i]-mid>0){
			sum+=arr[i]-mid;
			if(sum>=m){
				return true;
			}
		}
	}
	return false;
}

int getheight(int arr[],long long  n ,long long  m){
	int ans;
	int s=0;
	int maxheight=0;
	for(long long  i=0;i<n;i++){
		maxheight=max(maxheight,arr[i]);
	}
	int e=maxheight;
	cout<<"e:"<<e<<endl;
	long long mid=s+(e-s)/2;
	while(s<=e){
		if(isPossible(arr,n,m,mid)){
			ans=mid;
			cout<<"ans:"<<ans<<endl;
			s=mid+1;
		}
		else
			e=mid-1;
		mid=s+(e-s)/2;
       
	}
	return ans;
}








int main(){
	long long int n;
	cin>>n;
	long long int m;
	cin>>m ;
	int height[n];
	for(int i=0;i<n;i++){
		cin>>height[i];
	}


	cout<<getheight(height,n,m);
	return 0;
}