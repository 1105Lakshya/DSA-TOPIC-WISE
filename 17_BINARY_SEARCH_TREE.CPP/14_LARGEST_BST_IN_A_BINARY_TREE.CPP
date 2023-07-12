// #APPROACH
/*
WE WILL RETURN SIZE,  MAX VALUE ,WEATEHR THAT NODE IS A BST OR NOT , MIN VALUE 
IN ORDER TO CHECK FOR ANY NODE WE WILL CHEKK WEATHER LEFT PART IS BST && RIGHT PART IS BST && CURRNODES DATA SHOULD BE LESS THAN THE 
MINMUM VALUE OBTAINED FROM ITS RIGHT AND SHOULD BE GREATER THAN MAXIMUM VALUE OBTAINDED FROM ITS LEFT 
*/



/*
class info{
    public:
    int maxi;
    int mini;
    bool isBst;
    int size;
};
info solve(TreeNode<int>* root , int & ans){
    if(root==NULL){
        return {INT_MIN ,INT_MAX ,true ,0};
    }
    info left=solve(root->left ,ans);
    info right = solve(root->right , ans);
    info currNode;
    
    currNode.size=left.size+1+right.size;
    currNode.maxi=max(root->data, right.maxi);
    currNode.mini=min(root->data ,left. mini);
    
    if(left.isBst && right.isBst && (root->data >left.maxi && root->data<right. mini))
    {
        currNode.isBst=true;
        ans=max(currNode.size, ans);
    }
    else{
        currNode.isBst=false;
    }
    return currNode;
}
int largestBST(TreeNode<int>* root) 
{
    int maxSize=0;
    info temp=solve(root, maxSize);
    return maxSize;
}
*/