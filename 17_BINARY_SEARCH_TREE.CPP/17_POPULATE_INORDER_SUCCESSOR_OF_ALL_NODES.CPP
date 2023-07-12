/*
Given a Binary Tree, write a function to populate next pointer for all nodes. The next pointer for every node should be set to point to inorder successor.

Example 1:

Input:
           10
       /  \
      8    12
     /
    3
  

Output: 3->8 8->10 10->12 12->-1
Explanation: The inorder of the above tree is :
3 8 10 12. So the next pointer of node 3 is 
pointing to 8 , next pointer of 8 is pointing
to 10 and so on.And next pointer of 12 is
pointing to -1 as there is no inorder successor 
of 12.
Example 2:

Input:
           1
      /   \
     2     3
Output: 2->1 1->3 3->-1 
Your Task:
You do not need to read input or print anything. Your task is to complete the function populateNext() that takes the root node of the binary tree as input parameter.

*/






//SOLUTION

//             ALGO
/*
FIRST NODE KA INORDER SUCCESOR ASSIGN KRDIYYAA
FIR SOLVE FUNCTION KI CALL MARRDII

AGAR ROOT KA RIGHT EXIST KRTAA HUAA TOH TOH UTHHA KE LEAYYEE SUCCESSOR WRNAA JO FUNCTION CALL MEI SUCCESOR PASS KIYA WOH ASSIGN KRDIYA

ROOT KE LEFT MEIII  AS A SUCCESOR ROOT HI PASS KRDIYYAA KYUKI LEFT NODE RIGHT TOH LEFT KE BAAD NODE HI AYYEGAA
OR RIGHT MEI ROOT KA JO SUCCESOOR THA WO PASS KRDIYYYA KYUKII RIGHT KE BAAD ROOT JISKAAA LEFT HOGGA WO AYYEGAA
*/





/*
class Solution
{
private:
 
void     solve(Node* root ,Node * succ ) {
    if(root== NULL)
    return ;
    
    if(root->right==NULL){
        root->next= succ;
    }
    else{
        Node* succ=root->right;
        while(succ->left!=NULL)
        {
            succ=succ->left;
        }
        root->next=succ;
    }
    
    solve(root->left ,root);
    solve(root->right ,succ);
    
} 
public:

    void populateNext(Node *root)
    {
        if(root-> right ){
            Node* succ=root->right;
            while(succ->left!=NULL)
                succ=succ->left;
                
            root->next= succ;
        }
        
;
    solve( root->left , root );
    solve(root->right , NULL);
   
    }
};


*/