//(a+b)%m=a%m+b%m;
//a%m-b%m==(a-b)%m;
// ((a%m)%m)=a%m
// a%m  *  b%m== (a*b)%m;

// 1 <= T <= 100   
// 1 <= X, N, M <= 10^9

// Time limit: 1 sec

#include <bits/stdc++.h> 
int modularExponentiation(long long int x, int n, int m) {
	int result=1;
	while(n>0){
		if(n&1){
		result=((result)%m*(x)%m)%m;
		}
		x=((x)%m*(x)%m)%m;
		n=n>>1;
	}
return result %m;
}


#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}