//A BALANCED BST IS A TREE HAVING DIFFERENCE BETWEEN HEIGHTS OF LEFT AND RIGHT SUBTREE LESS THAN OR EQUAL TO ONE FOR ALL NODES



// ALGO: SAVE INORDER TRAVERSAL CALL FOR ROOT KA LEFT AND ROOT KA RIGHT BY MAKING A CURRENT NODE



/*

void solve(TreeNode<int>* root , vector <int > & vect){
    if(root==NULL)
        return ;
    solve(root->left , vect);
    vect.push_back(root->data);
    solve(root->right,vect);
    
}

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