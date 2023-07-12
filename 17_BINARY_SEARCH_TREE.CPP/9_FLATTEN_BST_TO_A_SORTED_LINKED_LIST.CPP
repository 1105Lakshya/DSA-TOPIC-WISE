/*

//REFER TO FLATTEN A TREE TO DLL 
void solve(TreeNode<int>* root,TreeNode<int>* &prev,TreeNode<int>* &head){
    if(root==NULL)
        return ;
    solve(root->left, prev, head);
    
    //solving for current node
    if(prev==NULL){
        head=root;
        prev=root;
    }
    else
    {
        prev->right=root;
        root->left=NULL;
        prev=root;
    }
    
    solve(root->right ,prev, head);
    
    
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    TreeNode<int>*prev=NULL;
    TreeNode<int>*head=NULL;
    solve(root, prev, head);
    return head;
}

*/


// NOTE:ANOTHER SOLUTION IS STORE INORDER TRAVERSAL IN A VECTOR AND ITEREATE THROUGH THE VECTOR AND CREAATE A LINKED LIST