/*
 
    Following is the Binary Tree node structure

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


    

void  solve(BinaryTreeNode<int>* root, int k, int& counter ,int &ans){
  if(root==NULL)
      return ;
    
    solve(root->left , k , counter, ans);
    counter++;
    if(counter==k)
        ans=root->data;
    solve(root->right, k ,counter ,ans);
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int ans=-1;
    int counter=0;
    solve(root, k ,counter ,ans);
    return ans;
}



*/