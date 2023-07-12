/*

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
leetcode
*/


/*
class Solution {
   bool compare_Nodes(TreeNode* root1 ,TreeNode*root2 ){
       if(root1==NULL && root2==NULL)
           return true;
       if(root1==NULL && root2!=NULL )
           return false;
       if(root1!=NULL && root2==NULL)
           return false;
       
       bool cond1=compare_Nodes(root1-> left , root2->right);
       bool cond2=(root1->val==root2->val);
       bool cond3=compare_Nodes(root1->right, root2->left);
       
       if(cond1 && cond2 && cond3)
           return true ;
       else
           return false;
   } 
    
public:
    bool isSymmetric(TreeNode* root) {
        return compare_Nodes(root->left, root->right);
    }
};


*/