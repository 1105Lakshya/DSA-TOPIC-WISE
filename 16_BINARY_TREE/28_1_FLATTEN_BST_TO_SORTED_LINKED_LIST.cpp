/*
You are given a Binary Search Tree (BST) with n nodes, each node has a distinct value assigned to it. The goal is to flatten the tree such that, the left child of each element points to nothing (NULL), and the right child points to the next element in the sorted list of elements of the BST (look at the examples for clarity). You must accomplish this without using any extra storage, except for recursive calls, which are allowed.

Note: If your BST does have a left child, then the system will print a -1 and will skip it, resulting in an incorrect solution.
*/

#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* right;
    Node* left;

};

class Solution
{
    void convert(Node* root , Node* &head){
        if(root==NULL)return;
        
        
        convert(root->right,head);
        root->right=head;
        head=root;
        convert(root->left,head);
        root->left=NULL;

    }
public:
    Node *flattenBST(Node *root)
    {
       Node* head=NULL;
       convert(root,head);
       
       return head;
    }
};

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    
    return 0;
}