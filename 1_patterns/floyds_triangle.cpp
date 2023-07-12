//************************************chutiya method by lakshya**********************************************************

// #include<iostream>
// using namespace std;

// int main(){
//     int n;
//     cout<<"enter the nuber of rows in floyd triangle u want to see"<<endl;
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=i;j++){
//             int k=i-1;
//             k=k*(k+1)/2;
//             cout<<k+j<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }


// *******************************************piro method********************************************************
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int count=1;
       for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<count<<" ";
            count++;
        }
        cout<<endl;
    }
    
    return 0;
}