#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string str="ajfalkflfj";
    // convert into upper
    // for(int i=0;i<str.size();i++){
    // if(str[i]>= 'a'  && str[i]<='z'){
    //     str[i]-=32;kdkk
    // }
    // }
    // cout<<str;

    // SHORTCUT

    transform(str.begin(),str.end(),str.begin(), :: toupper);
    cout<<str<<endl;
    transform(str.begin(),str.end(),str.begin(), :: tolower);
    cout<<str;
    return 0;
}