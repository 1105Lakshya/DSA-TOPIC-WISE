#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node( int d){
        this-> data=d;
        this-> prev=NULL;
        this-> next=NULL;
    }
    ~Node(){
        int val=this-> data;
        // if(next!=NULL){
        //     delete next;
        //     next=NULL;
        // }
        cout<<"memory free for node with data "<< val<<endl;
    }    
};

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;

}

int getlength(Node* head){
        int len=0;
    while(head!=NULL){
        len++;
        head=head->next;
    }
    return len;
}


void insertAtHead(Node* & head,int data){
    if(head==NULL){
    Node*temp =new Node(data);
    head=temp;
    }
    Node*temp =new Node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;

}


void insertAtTail(Node* & tail,int data){
    Node* temp=new Node(data);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}


void insertAtPosition(Node* & tail,Node*&  head ,int position ,int data){
    if (position == 1){
        insertAtHead(head, data);
        return;
    }

    Node* temp=head;
    int cnt=1;
    //taking the pointer at node jiske baad insert karnaa hai
    while(cnt<position -1){
        temp=temp->next;
        cnt++;
    }

    //if position is last then inserrtionn is at last
     if(temp->next==NULL){
        insertAtTail(tail,data);
        return ;
    }


    //insertion at middle
    Node*nodetoinsert=new Node(data);
    nodetoinsert->next=temp->next;
    temp->next->prev=nodetoinsert;
    nodetoinsert->prev=temp;
    temp->next=nodetoinsert;

}


void deleteNode(int position,Node* &head,Node* & tail){
    //code for deletion of first position 
    if(position ==1){
        Node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }else{

    //deleting any middle or last node

    Node*curr=head;
    Node*prev=NULL;

    int cnt=1;
    while(cnt<position){
        prev=curr;
        curr=curr->next;
        cnt++;
    }
    curr-> prev =NULL;
    prev-> next=curr->next;
    curr->next=NULL;

    // deleting current
    // curr->next =NULL;
    delete curr;
    }
}

int main(){
    Node* node1=new Node(10);
    Node*head=node1;
    print(head);

    cout<<"the length of linked list is "<<getlength(head)<<endl;

    insertAtHead(head,11);

    Node* tail=node1;
    insertAtTail(tail , 23);
    print(head);
    insertAtTail(tail , 69);
    print(head);
    

    insertAtPosition(tail,head,2,100);
    print(head);
    insertAtPosition(tail,head,1,999);
    print(head);
    insertAtPosition(tail,head,7,10101);
    print(head);

    deleteNode(1,head,tail);
    print (head);
    cout<< "head  :  "<<head->data<<endl;
    cout<< "tail  :  "<<tail->data<<endl;

    deleteNode(3,head,tail);
    print (head);
    cout<< "head  :  "<<head->data<<endl;
    cout<< "tail  :  "<<tail->data<<endl;

    deleteNode(5,head,tail);
    print (head);
    cout<< "head  :  "<<head->data<<endl;
    cout<< "tail  :  "<<tail->data<<endl;

    return 0;
}