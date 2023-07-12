#include<iostream>
using namespace std;

int main(){
    int len,width;
    cout<<"Enter the length and breadth of the rectangle "<<endl;
    cin>>len;
    cin>>width;
    for(int i=0;i<len;i++){
        for(int j=0;j<width;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}