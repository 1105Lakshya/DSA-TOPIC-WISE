/*Given a binary tree with N number of nodes, check if that input tree is Partial BST (Binary Search Tree) or not. If yes, return true, return false otherwise.*/



/*

 

    class BinaryTreeNode 
    {
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






void solve(BinaryTreeNode<int> *root, vector<int> & vect){
    if(root==NULL)
        return ;
    solve(root->left, vect);
    vect.push_back(root->data);
    solve(root->right, vect);
}
bool validateBST(BinaryTreeNode<int> *root) {
    vector<int> vect;
    solve(root, vect);
    int n=vect.size();
    for(int i=0;i<n-1;i++){
        if(vect[i]>vect[i+1]){
            return false;
        }
    }
    return true;
}







*/




//OPTIMAAL APPROACH
/*
bool isBST(BinaryTreeNode<int> *root,int min ,int max){
    if(root==NULL)
        return true;
    if(root->data> min && root->data<max)
    {
        bool left=isBST(root->left ,min ,root->data);
        bool right=isBST(root->right ,root->data,max);
        return left && right;
    }   
        return false;
}
bool validateBST(BinaryTreeNode<int> *root) {
    return isBST(root , INT_MIN, INT_MAX);
    
}





*/