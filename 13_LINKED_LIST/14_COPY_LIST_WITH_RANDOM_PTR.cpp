/*
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

 

Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
 

Constraints:

0 <= n <= 1000
-104 <= Node.val <= 104
Node.random is null or is pointing to some node in the linked list.

*/


#include<bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {

    void clone(Node* head, Node* ans){
        head=head->next;

        while(head!=NULL){
            Node* newNode=new Node(head->val);
            ans->next=newNode;
            ans=newNode;
            head=head->next;
        }

    }


    void merge(Node* head,Node*ans){
        Node* temp1;
        Node* temp2;
        while(head!=NULL){
            temp1=head->next;
            temp2=ans->next;

            head->next=ans;
            ans->next=temp1;

            head=temp1;
            ans=temp2;
        }

        
    }


    void clonerandom(Node* head){
        while(head!=NULL){
            if(head->random){
                head->next->random=head->random->next;
            }
            else{
                head->next->random=NULL;
            }
            head=head->next->next;
        }
    }


    void demerge(Node* head){
        Node* temp1;
        while(head->next!=NULL){
            temp1=head->next;
            head->next=head->next->next;
            head=temp1;
        }
    }





public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)return NULL;


        Node* ans=new Node(head->val);


        //cloned the linked list 
        clone(head,ans);

        

        //inserting the cloned list nodes in between our orignal list

        merge(head,ans);


        //clone random pointer 

        clonerandom(head);



        //demerge the clonned list from orignal list 

        demerge(head);


        return ans;

    }
};