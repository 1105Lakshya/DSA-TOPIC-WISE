/*
Given a binary tree, find out whether it contains a duplicate sub-tree of size two or more, or not.


Example 1 :

Input : 
               1
             /   \ 
           2       3
         /   \       \    
        4     5       2     
                     /  \    
                    4    5
Output : 1
Explanation : 
    2     
  /   \    
 4     5
is the duplicate sub-tree.
Example 2 :

Input : 
               1
             /   \ 
           2       3
Output: 0
Explanation: There is no duplicate sub-tree 
in the given binary tree.
*/


//here we will try to make preorder traversal string for each subtree and store it in a map



/*



class Solution {
  private:
  string solve(Node* root , unordered_map< string , int> & mp){
      if(root==NULL)
      return "$";                                               //we are returning dollar here because refer line 79
      
      if(root->left==NULL && root->right==NULL)        //leaf node toh single node hoggi koi tree ni hogga isliye usmei bas leaf ki value stiring mei convert krkke return karddii
      return to_string(root->data)+"*";           // adding extra star to differntiate between the data of left and right and node   
      
      string s="";
      string node=to_string(root->data)+"*";             
      string left=solve(root->left, mp)+"*";
      string right=solve(root->right,mp)+"*";
      s=s+node+left+right;            //present node ka preorder traveral node ka data+left se string + right se string
       
      mp[s]++;
      return s;
      
  }
  public:
    int dupSub(Node *root) {
         unordered_map<string ,int > map;
         solve(root, map);
         for(auto it:map){
             if(it.second>1)
             return 1;
         }
         
         return 0;
    }
};




*/


/*

        2                          2
       /  \              &&         \
      4     5                        4   
                                      \
                                       5      
the above both subtrees will have same preorder traversal so in order to differentiate them we will return dollar if one
of the child of a node is NULL 
*/




 