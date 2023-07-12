// #include<iostream>
// using namespace std;

// int main(){
//     int n;
//     cout<<"enter the size of pattern "<<endl;
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         for(int j=n; j>=1;j--){
//             if(i<=j){
//                 printf("*");
//             }
//             else{
//                 cout<<" ";
//             }
//         }
//         cout<<endl;
//     } 
//     return 0;
// }



// ************************************inverted half pyramid *******************************************************************
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the size of pattern "<<endl;
    cin>>n;
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}


// ************************************inverted half pyramid after 180deg rotation *******************************************************************


// #include<iostream>
// using namespace std;

// int main(){
//     int n;
//     cout<<"enter the size of pattern "<<endl;
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             if(j<=n-i){
//                 cout<<"  ";
//             }
//             else{
//                 cout<<"* ";
//             }
//         }
//         cout<<endl;
//     }
//     return 0;
// }