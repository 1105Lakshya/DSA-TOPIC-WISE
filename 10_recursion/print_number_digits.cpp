#include<iostream>
using namespace std;
void print_num(int n){
    if(n==0)
    return;
    int last_digit=n%10;
     n=n/10;
    print_num(n);
    switch(last_digit){
        case 0:
        cout<<"zero ";
        break;
        case 1:
        cout<<"one ";
        break;
        case 2:
        cout<<"two ";
        break;
        case 3:
        cout<<"three ";
        break;
        case 4:
        cout<<"four ";
        break;
        case 5:
        cout<<"five ";
        break;
        case 6:
        cout<<"six ";
        break;
        case 7:
        cout<<"seven ";
        break;
        case 8:
        cout<<"eight ";
        break;
        case 9:
        cout<<"nine ";
        break;
        return;
    }
}

int main(){
    int n;
    cin>>n;
    print_num(n);
    return 0;
}