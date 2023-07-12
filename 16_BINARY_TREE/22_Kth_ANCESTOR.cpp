/*
Input:
k=1 
node=3
      1
    /   \
    2     3

Output:
1
Explanation:
K=1 and node=3 ,Kth ancestor of node 3 is
*/




//ITERATIVE SOLUTION
/*
void   path(Node* root ,int node, stack<int> &ans){
    if(root == NULL)
    return;
    
    
    ans.push(root->data);
    
    if(root -> data == node){
        return ;
    }
    
    path(root ->left , node , ans);
    path(root ->right , node , ans);
    
    if(ans.top()==node   || ans.empty()){
        return;
    }
    else{
        ans.pop();
    }
}



int kthAncestor(Node *root, int k, int node)
{
    stack<int> ans;
    path(root, node ,ans);
    
    for(int i=0;i<k;i++){
        ans.pop();
        
        
        if(ans.empty())
        return -1;
        
        
    }
    return ans.top();
}

*/





//RECURSIVE
/*




bool  solve(Node* root , int  &k , int node , int& ans){
  if(!root)
  return false;
  
  if(root->data==node){
  k--;
  return true;
  }
  
  
  if(solve(root->left, k,node,ans)  || solve(root->right,k,node,ans) ){
  if(k==0){
      ans=root->data;
      k--;                //answer lock karnee ke liyye kardiyyyaa takkii negtive mei challa jayyee pr zero na hooo
      return true;
  }
  else{
      k--;
      return true;
      
  }
  }
  
  return false;
  
}

int kthAncestor(Node *root, int k, int node)
{
    int ans=-1;
    bool present=solve(root, k , node ,ans);
    
    return ans;
    
}




*/






//BABBAR BHIYYAA CODE 

/*
Node* solve(Node* root, int &k, int node) {
    //base case
    if(root == NULL)
        return NULL;
        
    if(root->data == node) 
    {
        return root;
    }
    
    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);


    //wapas
    if(leftAns != NULL && rightAns == NULL) 
    {
        k--;
        if(k<=0) 
        {
            //answer lock
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    
    if(leftAns == NULL && rightAns != NULL) {
        k--;
        if(k<=0) 
        {
            //answer lock
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
    

}
int kthAncestor(Node *root, int k, int node)
{
    Node* ans = solve(root, k, node);
    if(ans == NULL || ans->data == node)
        return -1;
    else
        return ans->data;
}

*/