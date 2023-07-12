#include<iostream>
using namespace std;
// *****************************************************JUST THE INTEGER PART OF THE SQUARE ROOT ************************************************************
long long int sqrtInteger(long long int n){
	int s=0;
	unsigned int e=n;
	long long int  mid=s+(e-s)/2;
	long long int ans=-1;
	while(s<=e){
		long long int sqr=mid*mid;
		if(sqr==n)
			return mid;
		if(mid*mid<n){
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
// ***************************************************FRACTIONAL PART OF THE SQUARE ROOT*************************************************************************
double morePrecision(int n,int precision,int tempsolution){
double factor =1;
double ans =tempsolution;

for(int i=0;i<precision;i++){
	factor=factor/10;
	for(double j=ans;j*j<n;j=j+factor){
		ans=j;
	}
}
return ans;
}





int main(){
	int n;
	cout<<"Enter the number "<<endl;
	cin>>n;
	int tempSol=sqrtInteger(n);
	cout<<tempSol;
    cout<<"Answer is "<< morePrecision(n,3,tempSol);
    return 0;
}