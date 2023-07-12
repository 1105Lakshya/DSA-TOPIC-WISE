#include<iostream>
#include<cmath>
using namespace std;
bool prime(int n){
        bool flag =true;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            flag=false;
            break;
        }
    }

return flag;
}

int main(){
    int n1,n2;
    cout<<"Enter the value of num1 and num2 "<<endl;
    cin>>n1>>n2;
    if(prime(n1+1)){
        cout<<n1+1;
    }
    for(int i=n1+2;i<n2;i++){
    if(prime(i)){
        cout<<","<<i;
    }

    }


    return 0;
}