
//********************************EUCLID ALGORITHM********************************************************************************************
//*********************************GCD(A,B)=GCD(A-B,B)****************************************************************************************
//*********************************lcm *hcf=product of two nuumbers*********************************************************8



#include<iostream>
using namespace std;

int gcd(int a,int b){
while(a!=0  && b!=0){
    if(a>=b)
    {
        a=a%b;
    }
    else
    {
        b=b%a;
    }
}
cout<<"MAI AAHHHUUAA"<<endl;

if (a==0){
    return b;
}
if(b==0){
    return a;
}
return 1;
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<endl; 
    return 0;
}