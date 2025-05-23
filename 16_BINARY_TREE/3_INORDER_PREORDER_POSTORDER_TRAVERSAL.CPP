//            INORDER                 PREORDER                POSTORDER
//              LNR                     NLR                     LRN









#include<bits/stdc++.h>
using namespace std;

class node{
    public:

    int data;
    node* left;
    node* right;
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};



//FUNCTION TO CREATE TREE
node* buildTree(node* root ){
cout<<"Enter the data :"<<endl;
int data;
cin>> data;
root=new node(data);

if(data==-1){
    return NULL;
}

cout<<"Enter the data for inserting in left OF"<<data<<endl;
root->left =buildTree(root-> left);
cout<<"Enter the data for inserting in the right OF "<<data<<endl;
root->right=buildTree(root->right);


return root;

}








/*********************************INORDER USING ITERATIVE AND RECURSIVE APRROACHES*****************************/

// RECURSIVE
void inorder(node* root){                     // LNR
    //base casee 
    if(root==NULL){
        return ;
    }

    inorder(root-> left);        //L 
    cout<<root->data<<" ";             //N
    inorder(root->right);           //R

}





//ITERATIVE
class Solution {
public:
    vector<int> inorderTraversal(node* root) {
        vector<int > ans;
        // create an empty stack
    stack<  node*> stack;
 
    // start from the root node (set current node to the root node)
    node* curr = root;
 
    // if the current node is null and the stack is also empty, we are done
    while (!stack.empty() || curr != nullptr)
    {
        // if the current node exists, push it into the stack (defer it)
        // and move to its left child
        if (curr != nullptr)
        {
            stack.push(curr);
            curr = curr->left;
        }
        else {
            // otherwise, if the current node is null, pop an element from the stack,
            // print it, and finally set the current node to its right child
            curr = stack.top();
            stack.pop();
            ans.push_back(curr->data);
 
            curr = curr->right;
        }
    }
        return ans;
    }
};







/*********************************PREORDER USING ITERATIVE AND RECURSIVE APRROACHES*****************************/


//RECURSIVE
void preorder(node* root){                     // LNR
    //base casee 
    if(root==NULL){
        return ;
    }

    cout<<root->data<<" ";             //N
    preorder(root-> left);        //L 
    preorder(root->right);           //R

}



// Iterative function to perform preorder traversal on the tree
void preorderIterative(node* root)
{
    // return if the tree is empty
    if (root == nullptr)
    return;
 
    // create an empty stack and push the root node
    stack<node*> stack;
    stack.push(root);
 
    // loop till stack is empty
    while (!stack.empty())
    {
        // pop a node from the stack and print it
        node* curr = stack.top();
        stack.pop();
 
        cout << curr->data << " ";
 
        // push the right child of the popped node into the stack
        if (curr->right) {
            stack.push(curr->right);
        }
 
        // push the left child of the popped node into the stack
        if (curr->left) {
            stack.push(curr->left);
        }
 
        // the right child must be pushed first so that the left child
        // is processed first (LIFO order)
    }
}



/*********************************POSTORDER USING ITERATIVE AND RECURSIVE APRROACHES*****************************/



//RECURSIVE
void postorder(node* root){                     // LNR
    //base casee 
    if(root==NULL){
        return ;
    }

    postorder(root-> left);        //L 
    postorder(root->right);           //R
    cout<<root->data<<" ";             //N

}



// Iterative function to perform postorder traversal on the tree

//USING TWO STACKS 
void postorderIterative(node* root)
{
    // return if the tree is empty
    if (root == nullptr) {
        return;
    }
 
    // create an empty stack and push the root node
    stack<node*> s;
    s.push(root);
 
    // create another stack to store postorder traversal
    stack<int> out;
 
    // loop till stack is empty
    while (!s.empty())
    {
        // pop a node from the stack and push the data into the output stack
        node* curr = s.top();
        s.pop();
 
        out.push(curr->data);
 
        // push the left and right child of the popped node into the stack
        if (curr->left) {
            s.push(curr->left);
        }
 
        if (curr->right) {
            s.push(curr->right);
        }
    }
 
    // print postorder traversal
    while (!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
    }
}



//USING ONE STACK 

void postorderIterative(node* root)
{
    // return if the tree is empty
    if (root == nullptr) {
        return;
    }
 
    // create an empty stack and push the root node
    stack<node*> st;
    
    node*curr=root;

    while (!st.empty() || curr!=NULL){
        if(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        else{
          node*  temp=st.top()->right;
          if(temp==NULL)
          {
            temp=st.top();
            st.pop();
            cout<<temp->data<<" ";
            while(!st.empty()  && temp==st.top()->right){
                temp=st.top();
                st.pop();
                cout<<temp->data<<" ";
            }
          }
            else{
                curr=temp;
            }
        }

    }
 
 
}






















int main(){
    node* root =NULL;
    //creating a Tree
    root = buildTree(root);

    cout<<"Inorder:";


    inorder(root);
    cout<<endl;

    cout<<"preorder:";
    preorder(root);
    cout<<endl;

    cout<<"postorder:";
    postorder(root);

    return 0;
}