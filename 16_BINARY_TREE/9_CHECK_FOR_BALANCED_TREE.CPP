/*

Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

A height balanced tree
        1
     /     \
   10      39
  /
5

*/




//O(N) solution using recursion 

/*

class Solution{
    private:
    pair<bool,int> isBalancedFast(Node *root){
    //base case
     if(root==NULL){
         pair<bool,int> p;
         p={true,0};
         return p;
     }
     pair<bool,int> left=isBalancedFast(root->left);
     pair<bool,int> right=isBalancedFast(root->right);
     
     bool leftAns=left.first;
     bool rightAns=right.first;
     bool diff=abs(left.second-right.second) <=1;
     
     pair<bool ,int> ans;
     if(leftAns && rightAns && diff ){
        ans.first=true ;
     }
     else{
         ans.first=false;
     }
     
     ans.second=max(left.second,right.second)+1;
     return ans;
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
    pair<bool,int> p=isBalancedFast(root);
    return p.first;
    }
    

    
};


*/