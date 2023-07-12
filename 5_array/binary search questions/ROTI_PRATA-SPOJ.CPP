#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> arr,int m,int mid){
	int count=0;
	int n=arr.size();
	for(int i=0;i<n;i++){
		int TIME=arr[i];
		int j=2;
		while(TIME<=mid ){
			count++;
			TIME+=arr[i]*(j);
			j++;
		if(count==m){
		return true;
		}
		}

	}
return false;	
}




int minCookTime(vector<int> &rank, int m)
{   int n=rank.size();
    int ans=0;
	int s=0; 
	int maxi=0;
for(int i=0;i<n;i++){
	maxi=max(maxi,rank[i]);
}
 int e=maxi*(m*(m+1)/2);
//  cout<<"maxi:"<<maxi<<endl;
//  cout<<"e:"<<e<<endl;
int	mid=s+(e-s)/2;
 
	while(s<=e){
// 		cout<<"mid:"<<mid<<endl;
		if(isPossible(rank,m,mid)){
			ans=mid;
// 			cout<<"ans:"<<ans<<endl;
			e=mid-1;
		}
		else{
			s=mid+1;
		}
		
		mid=s+(e-s)/2;
	}

// cout<<"real ans :";
return ans;


}
int main(){
    
    return 0;
}