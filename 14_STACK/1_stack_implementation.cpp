#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    int *arr;
    int size;
    int top;

    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }
    void push(int element ){
        // entering element in stack
        if(size-top> 1){
            top++;
            arr[top]=element;
        }      
        else{
            cout<<" STACK OVERFLOW"<<endl;
        }      
    }

// removing element from stack
    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"STACK UNDERFLOW"<<endl;
        }
    }

//getting top element of stack
    int  peek(){
        if(top>=0 ){
            return arr[top];
        }
        else{
            cout<<"Stack is Empty "<<endl;
            return -1;
        }
    }


    bool isEmpty(){
        if(top!=-1)
        return false;
        else
        return true;
    }
};


int main(){
      //creation of stack
    stack<int> s;

    //push operataion on stack
    s.push(2);
    s.push(3);

    //pop
    s.pop();

    cout<<"printing top element "<<s.top()<<endl;

    if(s.empty()){
        cout<<"stack is empty "<<endl;
    }
    else{
        cout<<"stack is not empty"<<endl;
    }


    cout<<"size of stack is"<< s.size()<<endl;
    return 0;
}