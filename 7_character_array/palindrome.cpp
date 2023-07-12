#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter n"<<endl;
    cin>>n;
    char arr[n+1];
    cout<<"enter the character array"<<endl;
    cin>>arr;
    bool check = true;
    for(int i=0;i<n/2;i++){
        if(arr[i] != arr[n-1-i]){
        check =false;
        break;
        }
    }
    if(check==true)
    cout<<"word is a palindrome"<<endl;
    else{
        cout<<"word is not a palindrome";
    }
    return 0;
}