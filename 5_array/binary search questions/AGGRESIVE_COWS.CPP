//******************************code studio***************************************
#include<bits/stdc++.h>
using namespace std;
// ********************************************************MINIMUM KO MAXIMUM KARNAAAAAAAAAAAAAA**********************************************************************
bool ispossible(vector<int>& stalls,int n,int k,int mid){
	int cowcount=1;
	int lastPosition=stalls[0];           
	for(int i=0;i<n;i++){
		if(stalls[i]-lastPosition>=mid){
			cowcount++;
			if(cowcount==k){
				return true;
			}
			lastPosition=stalls[i];
		}
	}
	return false;
}


int aggressiveCows(vector<int> &stalls, int k)
{	sort(stalls.begin(),stalls.end());
	int n=stalls.size();
   int s=0;
   int maxi=stalls[n-1];
// 	for(int i=0;i<n;i++){
// 		maxi=max(maxi,stalls[i]);
// 	}
 int e=maxi;
 int ans=-1;
int	mid=s+(e-s)/2;
 while(s<=e){
	if(ispossible(stalls,n,k,mid)){
		ans=mid;
		s=mid+1;
	}
	else{
		e=mid-1;
	}
	mid=s+(e-s)/2;
 }
 return ans;
}


int main(){
    
    return 0;
}