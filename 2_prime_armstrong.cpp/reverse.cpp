#include<iostream>
using namespace std;

int rev(int a){
    int rev=0;
    while(a){
        int remainder = a%10;
        rev = rev*10+remainder;
        a=a/10;
    }
    return rev;

        
}




int main(){
    int n;
    cout<<"Enter a number and i will reverse it"<<endl;
    cin>>n;
    cout<<"The reversed number is : "<<rev(n)<<endl;
    return 0;
}