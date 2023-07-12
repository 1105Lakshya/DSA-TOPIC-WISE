//****************************CODE STUDIO : Reverse List In K Groups*********************************

#include<bits/stdc++.h>
using namespace std;

//****************************************************************
    // Following is the Linked List node structure

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

// ****************************************************************

Node* kReverse(Node* head, int k) {
	//base call
	if(head==NULL){
		return NULL;
	}
	//step 1 : reversing first k nodes
	Node * forward=NULL;
	Node * curr=head;
	Node* prev= NULL;
	int count=0;
	while(curr!=NULL  && count <k){
		forward=curr->next;
		curr->next=prev;
		prev=curr;
		curr=forward;
		count++;
	}
	
// 	step2: recursion dekhlegaa aggee kaa
	if(forward!= NULL){
		head->next =kReverse(forward,k);
	}
// 	step3:return head of reversed linked listt
	return prev;
}




int main(){
    
    return 0;
}