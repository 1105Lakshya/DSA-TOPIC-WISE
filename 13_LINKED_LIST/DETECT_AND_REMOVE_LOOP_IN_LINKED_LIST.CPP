#include<bits/stdc++.h>
using namespace std;



class Node{

    public:
    int data;
    Node* next;
    //constructor
    Node(int data ){
        this-> data=data;
        this-> next=NULL;
    }

    //destructor
    ~Node(){
        int value =this->data;
        //memory free
        if(this-> next !=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free for node with data "<<value<<endl;
    }

};


//********************FUNCTION TO DETECT LOOP IN A LINKED LIST  USING MAP ********************************


//TIME COMPLEXITY   O(N)
//SPACE COMPLEXITY  O(N)
bool detectloop(Node* head){
if(head == NULL){ 
    return false;
}

map<Node* ,bool> visited;           
Node*temp=head;
while(temp!=NULL){
    //cycle is present  
    if(visited[temp]==true){
        return false;
    }
    

    visited[temp]=true;
    temp=temp->next;


}
return false;
}




int main(){
    
    return 0;
}