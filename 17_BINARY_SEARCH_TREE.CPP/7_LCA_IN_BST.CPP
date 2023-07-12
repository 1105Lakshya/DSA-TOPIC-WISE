/*
You are given a binary search tree of integers with N nodes. You are also given references to two nodes P and Q from this BST.
Your task is to find the lowest common ancestor(LCA) of these two given nodes.
The lowest common ancestor for two nodes P and Q is defined as the lowest node that has both P and Q as descendants (where we allow a node to be a descendant of itself)
*/


/*

    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };



TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{

    int a=P->data;
    int b=Q->data;
    if(root->data<a  &&  root->data<b)              // matlab root right mei haii LCA
        return LCAinaBST(root->right,P,Q);
    else if(root->data>a  &&  root->data>b)
    {
        return LCAinaBST(root->left,P,Q);    
    }
    else
        return root;                               //agaar uppar mei se koi case ni haii toh jahh hum khaade hai wo hi LCA hai
}


*/