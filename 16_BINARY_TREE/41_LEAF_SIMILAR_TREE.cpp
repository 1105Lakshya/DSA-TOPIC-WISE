/*
Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.



For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

 

Example 1:


Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
Output: true
Example 2:


Input: root1 = [1,2,3], root2 = [1,3,2]
Output: false
 

Constraints:

The number of nodes in each tree will be in the range [1, 200].
Both of the given trees will have values in the range [0, 200].
*/


#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


//first make a vector of leaf nodes then push from that vector

  struct TreeNode {
    int val;
    TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
    vector<int> leaf;

    bool flag=true;
    void make_vec(TreeNode* root){
        if(root==NULL)return ;

        if(root->left==NULL && root->right==NULL){
            leaf.push_back(root->val);
            return ;
        }

        make_vec(root->left);
        make_vec(root->right);
    }


    void check_vec(TreeNode *root){
        if(root==NULL)return;

        if(!flag)return ;

        if(root->left==NULL && root->right==NULL){
            if(!leaf.empty() && root->val==leaf.back()){
                leaf.pop_back();
            }
            else{
                flag=false;
            }

            return ;
        }

        check_vec(root->right );
        check_vec(root->left);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        make_vec(root1);
        check_vec(root2);

        return (flag & leaf.empty());
    }
};

int main(){
    
    return 0;
}