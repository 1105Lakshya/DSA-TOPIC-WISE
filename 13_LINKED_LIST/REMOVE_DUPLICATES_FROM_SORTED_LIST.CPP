#include<bits/stdc++.h>
using namespace std;


//************************************************************

    // Following is the linked list node structure.
    
    class Node 
    {
        public:
        int data;
        Node* next;

        Node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
    };
    
// ***********************************************************

Node * uniqueSortedList(Node * head) {
	Node* ans=head;
//EMPTY LIST
	if(head==NULL  ||  head-> next ==NULL){
		return head;
	}
	while( head-> next !=NULL){
		if(head->data==head->next->data){
			Node* temp= head->next;
			head->next=head->next->next;
			delete temp;
			continue;
		}
			head=head->next;
	}
		return ans;
}

int main(){
    
    return 0;
}