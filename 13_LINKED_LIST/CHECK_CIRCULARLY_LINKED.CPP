#include<bits/stdc++.h>
using namespace std;

        class Node{
        public:
            int data;
            Node* next;
            
            Node(int data){
                this->data = data;
                this->next = NULL;
            }
            
        };



bool isCircular(Node* head){
	if(head==NULL){
		return true;
	}
	if(head->next==NULL){
		return false;
	}
	
	Node*temp=head->next;
	while(temp!=head  ){
		if(temp==NULL){
			return false;
		}
		temp=temp->next;
	}
	return true;
}
int main(){
    
    return 0;
}