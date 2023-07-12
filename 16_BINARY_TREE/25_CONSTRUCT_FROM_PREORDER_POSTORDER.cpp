/*

889. Construct Binary Tree from Preorder and Postorder Traversal
Medium
2.5K
100
Companies
Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.

If there exist multiple answers, you can return any of them.

 

Example 1:


Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]
Example 2:

Input: preorder = [1], postorder = [1]
Output: [1]
 

Constraints:

1 <= preorder.length <= 30
1 <= preorder[i] <= preorder.length
All the values of preorder are unique.
postorder.length == preorder.length
1 <= postorder[i] <= postorder.length
All the values of postorder are unique.
It is guaranteed that preorder and postorder are the preorder traversal and postorder traversal of the same binary tree.



*/


//bas ismei na pre order ko index banaiyoo or usmei agge ki side traverse kariiooo

#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    TreeNode*  left;
    TreeNode*  right;

    int data;

    TreeNode(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }


};

class Solution {
public:
   TreeNode *maketree(vector<int>& preorder, vector<int>& postorder,int &preidx,int left,int right,int size)
{
    if(left>right || preidx>=size)
        return NULL;
    
    TreeNode *root=new TreeNode(preorder[preidx]);
    preidx++;
    if(left==right)
        return root;
    int i=0;
    for(i=left;i<=right;i++)
    {
        if(preorder[preidx]==postorder[i])
            break;
    }
    if(i<=right)
    {
        root->left=maketree(preorder,postorder,preidx,left,i,size);
        root->right=maketree(preorder,postorder,preidx,i+1,right-1,size);
    }
    return root;
}

TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) 
{
    int preidx=0;
    return maketree(preorder,postorder,preidx,0,preorder.size()-1,preorder.size());    
}
};