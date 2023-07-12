#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node*prev;
    Node(int d){
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }
};

class Stack{
    public:
    Node* head;

    Stack(){
        this->head=NULL;
    }
    
    void push(int data){
        if(head==NULL){
        Node* temp=new Node(data);
        head=temp;    
        }
        else{
        Node* temp=new Node(data);
        head->next=temp;
        temp->prev=head;
        head=temp;
        }
    }

    void pop(){
        if(head==NULL){
            cout<<"stack Underflow"<<endl;
        }
        else{
            Node* temp=head;
            head=head->prev;
            head->next=NULL;
            temp->prev=NULL;
            delete temp;
        }
    }

    int  top(){
        if(head==NULL){
            cout<< "stack is empty"<<endl;
            return -1;
        }
        else{
            return head->data;
        }
    }

    bool isEmpty(){
        if(head==NULL){
            return true;
        }
        else{
            return false;
        }
    }

};

int main(){
    Stack st;
    st.push(69);
    st.push(11);
    st.push(96);
    st.push(9621);
    st.push(921);
    cout<<"Top element is :"<<st.top()<< endl;
    st.pop();
    cout<<"Top element is :"<<st.top()<< endl;
    st.pop();
    cout<<"Top element is :"<<st.top()<< endl;
    if(st.isEmpty()){
        cout<<"st  is empty"<<endl;

    }else{
        cout<<"st is not empty"<<endl;
    }
    return 0;
}