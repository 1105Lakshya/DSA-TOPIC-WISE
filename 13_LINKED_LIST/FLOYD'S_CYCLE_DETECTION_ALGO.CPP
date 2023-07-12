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

// // FLOYD'S CYCLE DETECTIION ALGOOOO
Node* floydDetect(Node* head){     //TIME COMPLEXITY   O(N)
  if(head ==NULL){                 //SPACE COMPLEXITY   O(1)
        return head;
    }
    Node* slow =head;
    Node* fast=head;
    while(fast !=  NULL  && slow!=NULL){
        fast =fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if(slow==fast){
            return slow;    //matlab jo return hoggaa wo loop mei present hogaa beginning of the loop nahiii hogaa
        }
    }
return NULL;
}



// // FUNCTION FOR USING FLOYD'S LOOP DETECTION ALGO FINDING THE BEGINNNING  OF THE LOOP
// 1.  FCD ALGO ->  FIND THE POINT OF INTERSECTION
// 2.  SLOW=HEAD
// 3.  FIR SLOW OR HEAD KO DONOO KO EK EK SE AGEE BHADAAAOOOO JAHHHAAAA MILLE WO BEGINNING OF LOOP


Node* getstartingnode(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* intersection =floydDetect(head);
	if(intersection ==NULL){  // matlab loop hi nahhi haii
	return NULL;
	}
    Node* slow =head;
    while(slow != intersection){
        slow= slow-> next;
        intersection =intersection-> next;
    }
    return slow;
}



Node *removeLoop(Node *head)
{
     if(head== NULL ){
         return head;
     }

Node* startofloop=getstartingnode(head);
	if(startofloop==NULL){
		return head;
	}
     Node* temp= startofloop;
     while(temp-> next != startofloop ){
         temp=temp->next;
     }
     temp-> next = NULL;

return head;
}




int main(){
    
    return 0;
}