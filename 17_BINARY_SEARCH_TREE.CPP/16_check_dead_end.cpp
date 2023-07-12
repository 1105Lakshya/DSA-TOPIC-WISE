/*

Given a Binary search Tree that contains positive integer values greater then 0. The task is to complete the function isDeadEnd which returns true if the BST contains a dead end else returns false. Here Dead End means, we are not able to insert any element after that node.

Examples:

Input :   
               8
             /   \ 
           5      9
         /  \     
        2    7 
       /
      1     
          
Output : Yes
Explanation : Node "1" is the dead End because after that 
              we cant insert any element.       

Input :     
              8
            /   \ 
           7     10
         /      /   \
        2      9     13

Output : Yes
Explanation : We can't insert any element at 
              node 9. 


*/






//#APPROACH:::::> RANGE PASS KRNEE WALIII APPROACH 
/*
bool solve(int start ,int end , Node* root){
    if(root==NULL)
    return false;
    
    int range=end-start ;
    if(range==2)
    return true;
    
    int cond1=solve(start ,root->data , root->left);
    int cond2=solve(root->data ,end , root->right);
    
    
    return (cond1 || cond2);
    
    
}
bool isDeadEnd(Node *root)
{
    int start =0;
    int end=INT_MAX;
    return solve(start ,end , root);
}

*/