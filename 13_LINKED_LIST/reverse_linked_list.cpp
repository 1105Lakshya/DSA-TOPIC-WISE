
//REVERSE A LINKED LIST SEE SOLUTION ON CODE STUDIOOO Q NAME REVERSE A LINKED LIST







// ********************************iterative*****************************************************
#include <bits/stdc++.h> 
using namespace std;
// // ****************************************************************

//     // Following is the class structure of the LinkedListNode class:

//     template <typename T>
//     class LinkedListNode
//     {
//     public:
//         T data;
//         LinkedListNode<T> *next;
//         LinkedListNode(T data)
//         {
//             this->data = data;
//             this->next = NULL;
//         }
//     };

// // *****************************************************************






//                                                                  iterative       solution
// LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
// {   if(head==NULL  || head->next==NULL){
// 	return head;
	
// }
//     LinkedListNode<int> *prev=NULL;
// 	LinkedListNode<int> *curr=head;
// 	while(curr!=NULL){
// 		LinkedListNode<int> *forward=curr->next;
// 		curr->next=prev;
// 		prev=curr;
// 		curr=forward;
// 	}
// 	return prev;
// }





// RECURSIVE
// void reverse(LinkedListNode<int>* &head,LinkedListNode<int>*curr,LinkedListNode<int> *prev){
// 	//base case
// 	if(curr==NULL){
// 		head=prev;
// 		return;
// 	}
// 	LinkedListNode<int> *forward =curr-> next;
// 	reverse(head,forward,curr);
// 	curr->next=prev;
	
// }



                                                       // REVERSE DOUBLY GFG



                                                       
// Node*  reversedoubly(Node* head){
//     //base case
//     if(head==NULL || head ->next==NULL){
//         return head;
//     }
//     Node*temp=head->next;
//     head->next->prev=NULL;
//     Node*chottahead=reversedoubly(head->next);
//     head->prev=temp;
//     head->next->next=head;
//     head->next=NULL;
    
    
//     return chottahead;
    
// }

// Node* reverseDLL(Node * head)
// {
//     Node * ans=reversedoubly(head);
//     return ans;
// }
