//NOTE1--->  inorder predecessor is the data that gets printed before the particular data in inorder traversal 





/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
*/


//RECURSIVE WAY
/*
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    if(root==NULL){
        return false;
    }
    
    if(root->data==x)
    return true;
    
    
    if(root->data >x ){
       return searchInBST(root->left ,x);
    }
    else{
       return searchInBST(root->right ,x);
    }
    
}

*/



//ITERATIVE WAY

/*

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    if(root==NULL)
        return false;
    
    while(root!=NULL)
    {
        if(root->data>x)
            root=root->left;
        else if(root->data<x)
            root=root->right;
        else
            return true;
    }
    return false;
}




*/