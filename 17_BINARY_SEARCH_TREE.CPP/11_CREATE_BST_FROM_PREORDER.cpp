/*From PREORDER = [20, 10, 5, 15, 13, 35, 30, 42] , the following BST can be constructed:*/


// O(squr(N)) time complexity using recursion
/*
BinaryTreeNode<int>* solve(vector<int> & preorder ,int start, int end){
    if(start>end)
        return NULL;
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(preorder[start]);
    int mid=start+1;
    while(mid<end+1 ){
        if(preorder[start]<preorder[mid])
            break;
            mid++;
    }
    root->left=solve(preorder , start+1,mid-1);
    root->right = solve(preorder ,mid ,end);
    return root;
    
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    return solve(preorder , 0 ,preorder.size()-1);
}

*/



// best approachh 

// ALGO
/*


*/
/*

BinaryTreeNode<int>* solve(vector<int> & preorder , int mini ,int maxi , int &index){
    if(index>=preorder.size()  || preorder[index]<mini || preorder[index]>maxi){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[index++]);
    root->left=solve(preorder, mini, root->data, index);
    root->right=solve(preorder, root->data ,maxi,index);
    return root;
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int mini=INT_MIN;
    int maxi=INT_MAX;
    int index=0;
    return solve(preorder , mini,maxi , index);
}


*/