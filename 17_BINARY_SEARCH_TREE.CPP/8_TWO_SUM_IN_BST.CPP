/*
You have been given a Binary Search Tree and a target value. You need to find out whether there exists a pair of node values in the BST, such that their sum is equal to the target value.
*/


/*
// Following is the Binary Tree node structure
%**************************************
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
*******************************************%


//solution: INORDER TRAVERSAL KRKE TWO SUM SOLVE 
void solve(BinaryTreeNode<int>* root , vector <int > & vect){
    if(root==NULL)
        return ;
    solve(root->left , vect);
    vect.push_back(root->data);
    solve(root->right,vect);
    
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	vector< int > vect;
    solve (root, vect);
    
    int n=vect.size();
    int i=0;
    int j=n-1;
    while(i< j){
        if(vect[i]+vect[j]==target)
            return true;
        if(vect[i]+vect[j]<target)
            i++;
        if(vect[i]+vect[j]>target)
            j--;
    }
    return false;
}


*/