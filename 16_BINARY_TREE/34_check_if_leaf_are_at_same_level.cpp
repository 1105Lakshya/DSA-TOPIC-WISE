/*



Given a Binary Tree, check if all leaves are at same level or not.

Example 1:

Input: 
            1
          /   \
         2     3

Output: 1

Explanation: 
Leaves 2 and 3 are at same level.

Example 2:

Input:
            10
          /    \
        20      30
       /  \        
     10    15

Output: 0

Explanation:
Leaves 10, 15 and 30 are not at same level
*/






/*

class Solution{
  private:
  void  solve(Node* root  ,pair<int , bool> &check, int level){
      if(root==NULL)
      return ;
      
      
      solve(root->left , check , level+1);
      
      if(root->left==NULL && root-> right==NULL){
      bool cond1=check.second;
      bool cond2=(check.first==level || check.first==0);
      check.first=level;
      if(cond1 && cond2 )
      check.second=true;
      else
      check.second=false;
      
      
      return ;
      }
      
      solve(root->right , check , level +1);
      
      
      
  }
  public:
    bool check(Node *root)
    {
        pair<int ,bool> check=make_pair(0,true);
        solve(root , check , 0);
        return check.second;
    }
};




*/