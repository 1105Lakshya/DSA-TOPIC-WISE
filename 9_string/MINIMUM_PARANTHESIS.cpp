#include<bits/stdc++.h>
using namespace std;

int minimumParentheses(string str) {
int n=str.size();
int count1=0;
int count2=0;
int i=0;
	while(i<n){
		while(i<n && str[i]==')'){
			count2++;
			i++;
		}
		while(i<n && str[i]=='('){
			count1++;
			i++;
		}
		while(count1>0 && i<n && str[i]==')'){
			i++;
			count1--;
		}
	}
	return count1+count2;
}
	



int main(){
    
    return 0;
}