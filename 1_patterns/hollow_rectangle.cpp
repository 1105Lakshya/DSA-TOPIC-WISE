#include<iostream>
using namespace std;

int main(){
    int len,breadth;
    cout<<"enter the length and breadth of the rectangle "<<endl;
    cin>>len>>breadth;
    cout<<len<<"\t"<<breadth<<endl;
    for(int i=0;i<len;i++){
        if(i==0 || i==len-1){
            for(int j=0;j<breadth;j++){
                cout<<"* ";
            }
            cout<<endl;
        }
        else{
            cout<<"*";
            for(int k=0;k<2*breadth-3;k++){
                cout<<" ";
            }
            cout<<"*"<<endl;
            
            
        }
    }


    return 0;
}