#include<iostream>
using namespace std;
//CREATE AN ARRAY CHECK ARRAY AND ASSIGN ALL VALUE TO FALSE THEN  ASSIGN TRUE AT THE INDEX OF CHECK ARRAY FROM ELEMENT FROM GIVEN ARRAY
// THEN THE FIRST FALSE IN THE CHECK ARRAY GIVES THE ANSWER
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    const int N =1e6+2;
    bool check[n];
    for(int i=0;i<N;i++){
        check[i]=false;
    }
    return 0;
}