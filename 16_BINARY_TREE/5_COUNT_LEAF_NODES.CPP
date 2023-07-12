#include<bits/stdc++.h>
using namespace std;

//ALGO
/*
DO INORDER TRAVERSAL IF ENCOUNTER A LEAF NODE COUNT++
*/

/**********************************************************

    Following is the Binary Tree Node class structure:*/

    template <typename T>
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
    
//********************function to count leaf node in tree through inorder traversal***************
void count_inorder_traversal(BinaryTreeNode<int> *root, int &ans){
    if(root == NULL)
        return ;
    count_inorder_traversal(root->left , ans);
    if(root-> left == NULL  && root-> right == NULL ){
        ans++;
    }
    count_inorder_traversal(root-> right , ans);

}


int noOfLeafNodes(BinaryTreeNode<int> *root){
    int ans=0;
    count_inorder_traversal(root, ans ); 
    return ans;
}

//Complexity is O(n) where n is the number of nodes in tree



int main(){
    
    return 0;
}