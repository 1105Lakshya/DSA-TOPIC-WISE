#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    // fflush(stdin);
    cin.ignore();
    char arr[n+1];
    cout<<"enter the character array"<<endl;
    cin.getline(arr,n);    //gets of cpp
    int i=0;
    int currlen=0;
    int maxlen =0;
    int st=0,maxst=0;
    while(1){
            if(arr[i]==' ' || arr[i]== '\0'){
                maxlen=max(maxlen,currlen);
                currlen=0;
                st=i+1;
            }
            else{
                currlen++;
            }



        if(arr[i]=='\0')
        break;
        i++;
    }

    cout<<maxlen<<endl;
    return 0;
}