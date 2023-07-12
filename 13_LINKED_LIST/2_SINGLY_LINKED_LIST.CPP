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




//INSERTION IN A LINKED LIST AT START OR AT HEAD
void insertAtHead(Node* &head,int d){
    Node* temp=new Node(d);
    if(head==NULL)
    head=temp;

    //new node create
    temp-> next =head;
    head=temp;

}



//  TRAVERSING A LINKED LIST
void print(Node*  &head){
    Node*temp =head;
    while(temp!=NULL){
        cout<<temp-> data<<" ";
        temp=temp-> next;
    }cout<< endl;
}

//INSERTING IN A LINKED LIST AT END  OR AT TAIL
void insertAtTail(Node* &tail ,int data){
    Node *temp=new Node(data);
    tail->next=temp;
    tail =temp;

}


//INSERTING IN A LINKED LIST AT MIDDLE 
void insertAtMiddle(Node* &tail ,Node*  &head, int position ,int data){


    //inserting at starting position 
    if(position==1){
        insertAtHead(head,data);
        return;
    }
    Node* temp=head;
    int cnt=1;
    //taking the pointer at node jiske baad insert karnaa hai
    while(cnt<position -1){
        temp=temp->next;
    }

    //updatig tail if insertion at last position 
    if(temp->next==NULL){
        insertAtTail(tail,data);
        return ;
    }

    //creating a node for d
    Node*node_to_insert=new Node(data);
    node_to_insert -> next=  temp  ->  next;
    temp  ->  next=  node_to_insert;

}


void deleteNode(int position,Node* &head,Node* & tail){
    //code for deletion of first position 
    if(position ==1){
        Node* temp=head;
        head=head->next;       //head ko agge bhadaadiyyyyaaa
        //freeing the memory of first node 
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
    prev->next=curr->next;
    if(prev->next==NULL)
    tail=prev;
    
    // deleting current
    curr->next =NULL;
    delete curr;


    }
}


int main(){

    //created a new node
    Node* node1 = new Node(10);    
    // cout<<node1  -> data<< endl;
    // cout<<node1  -> next <<endl;

    //head pointed to new node1
    Node* head =node1;
    cout<<"printing from head abhii sirf ek hi node hai linked list mei"<<endl;
    print(head);
    insertAtHead(head,12);
    cout<<"After insertion at head"<<endl;
    print(head);
    insertAtHead(head,15);
    cout<<"After insertion at head"<<endl;
    print(head);


    //tail operations 
    Node* tail= node1;
    insertAtTail(tail, 45);
    cout<<"After insertion at tail"<<endl;
    print(node1);
    insertAtTail(tail,54) ;
    cout<<"After insertion at tail"<<endl;
    print(node1);


    //middle
    insertAtMiddle(node1,node1,2,69);
    cout<<"After insertion in middle at position "<< 2<<". "<<endl;
    print(node1);

    //verfying head and tail 
    cout<<"head:"<<head->data<<endl;
    cout<<"tail"<<tail->data<<endl;


    head=node1;
    deleteNode(4,head,tail);
    print(head);

    
    //verfying head and tail 
    cout<<"head:"<<head->data<<endl;
    cout<<"tail"<<tail->data<<endl;


    return 0;
}