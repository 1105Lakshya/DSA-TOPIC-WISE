/*
Given the root of a binary tree, return all duplicate subtrees.

For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with the same node values.

 

Example 1:


Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]
Example 2:


Input: root = [2,1,1]
Output: [[1]]
Example 3:


Input: root = [2,2,2,3,null,3,null]
Output: [[2,3],[3]]
 

Constraints:

The number of the nodes in the tree will be in the range [1, 5000]
-200 <= Node.val <= 200
*/

//POST ORDER TRAVERSAL KI STRING BANAKE MAP MEI STORE IF STRING PEHLE BHI EXIST THEN DUPLICATE SUBTREE OCCURES

//   Definition for a binary tree node.
  struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


#include<bits/stdc++.h>
using namespace std;


class Solution {
    private:
    string solve( TreeNode* root , unordered_map<string ,pair<int,TreeNode*>> & mp , vector<TreeNode*> &ans){
    if(root==NULL) 
return "$";


    
string present=to_string(root->val)+"*";
string left = solve(root->left ,mp,ans)+"*";
string right =solve(root-> right ,mp,ans)+"*";
string str="";
str=str+present+left+right;




if(mp.find(str)==mp.end())
{
    mp[str]=make_pair(1,root);
}

else{
    if(mp[str].first==1)
    ans.push_back(root);
    mp[str].first++;

}




 



return str;
 


}
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
    unordered_map<string ,pair<int,TreeNode*>> mp;
    string str=solve(root, mp, ans );
    // for(auto it:mp){
    //     if(it.second.first>1)
    //     ans.push_back(it.second.second);
        
    // }
return ans;
    }
};