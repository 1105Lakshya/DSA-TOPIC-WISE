/*

Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value. Else return false.

An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.


Example 1:

Input:
    3
  /   \    
 1     2

Output: 1

*/










/*
class Solution
{
    private:
    pair<bool,int> isSumTreeFast(Node* root){
        
        //base case
        if(root==NULL){
        pair<bool ,int > p=make_pair(true,0);
        return p;
        }


        //leaf node
        if(root->left==NULL && root -> right==NULL){
        pair<bool ,int > p=make_pair(true,root->data);
        return p;
        }
        
    pair<bool,int> left=isSumTreeFast(root->left);
    pair<bool,int> right=isSumTreeFast(root->right);
    bool curr=(left.second+right.second==root->data);
    
    pair<bool,int> ans;
    if(left.first  &&  right.first && curr){
        ans.first= true;
    }
    else{
        ans.first= false;
    }
    ans.second=left.second+right.second+root->data;
    return ans;
    
        
    }
    
    public:
    bool isSumTree(Node* root)
    {
         return isSumTreeFast(root).first;
    }
};

*/