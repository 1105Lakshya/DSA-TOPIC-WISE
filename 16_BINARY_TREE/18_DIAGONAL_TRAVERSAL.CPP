//GO TO GFG AND SEARCH DIAGONAL TRAVERSAL OF BINARY TREEE



// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector<int> diagonal(Node *root);







//SOLUTIONNNN OF DIAGONAL TRAVERSALLL


vector<int> diagonal(Node *root)
{
   queue<Node*> q;
   vector<int> ans;
   if(root==NULL)
   return ans;
   
   q.push(root);
   while(!q.empty()){
       Node*temp=q.front();
       q.pop();
       while(temp){
           if(temp->left) 
           q.push(temp->left);
           ans.push_back(temp->data);
           temp=temp->right;
       }
   }
   return ans;
}