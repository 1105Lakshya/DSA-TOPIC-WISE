/*
TreeNode<int>*     inorderToBST(int s ,int e , vector<int> vect)
{
    //base case
    if(s>e)
        return NULL;
    
    int mid= (s+e)/2;
    TreeNode<int>* root = new TreeNode<int>(vect[mid]);
    root->left=inorderToBST(s, mid-1 ,vect);
    root->right=inorderToBST(mid+1, e ,vect);
    return root;
}

*/