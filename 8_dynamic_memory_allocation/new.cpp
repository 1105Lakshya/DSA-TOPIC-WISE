#include<iostream>
using namespace std;

int main(){
    int a=10;
    int*p=new int();   
    *p=10;                     //stack mei ek pointer banna jo heap ke ek address pr point kr ra haii jahha pr 10 haii
    delete (p);      //deallocating the memory 
    p=new int [4];               // dynamic array 
    delete[]p;                     //deallocating the array 
    return 0;
}