#include<iostream>
using namespace std;
void print_palindrome(int n){
    for(int i=n;i>=1;i--){
        printf("%d ",i);
    }
    for(int i=2;i<=n;i++){
        printf("%d ",i);
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter the size of the pattern"<<endl;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            cout<<"  ";
        }
        print_palindrome(i);
        

    }
    
    return 0;
}