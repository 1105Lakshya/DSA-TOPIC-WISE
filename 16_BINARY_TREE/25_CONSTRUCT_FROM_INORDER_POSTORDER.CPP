/*

Given inorder and postorder traversals of a Binary Tree in the arrays in[] and post[] respectively. The task is to construct the binary tree from these traversals.

 

Example 1:

Input:
N = 8
in[] = 4 8 2 5 1 6 3 7
post[] =8 4 5 2 6 7 3 1
Output: 1 2 4 8 5 3 6 7
Explanation: For the given postorder and
inorder traversal of tree the  resultant
binary tree will be
           1
       /      \
     2         3
   /  \      /  \
  4    5    6    7
   \
     8
 

Example 2:

Input:
N = 5
in[] = 9 5 2 3 4
post[] = 5 9 3 4 2
Output: 2 9 5 4 3
Explanation:  
the  resultant binary tree will be
           2
        /     \
       9       4
        \     /
         5   3


*/


//bas last se shuruu kiyyaa and right ki call pehlee marrddiiii  bakkii inorder preorder jaiiisaaa hiii
/*
    int findPosition(int in[], int element, int size){
        for(int i=0;i< size;i++){
        if(in[i]==element)
        return i;
            
        }
        return -1;
    }
    
    Node* solve(int in[], int post[], int& index  , int inorderStart ,int inorderEnd , int size){
        //base case 
        if(index<0 || inorderStart>inorderEnd)     // dost ye condition rattlee visulaise krne ke liye dry run karlee
        return NULL;
        
        int element=post[index];
        index--;
        Node* root =new Node(element);
         
        int position_in_inorder=findPosition(in , element , size);
        
        
        //recursive call
        root-> right=solve(in , post , index , position_in_inorder+1, inorderEnd, size );
        root-> left=solve(in , post , index ,inorderStart, position_in_inorder-1 ,size);
        
        return root;
        
        
        
        
    }



Node *buildTree(int in[], int post[], int n) {
        int postorderIndex=n-1;
        Node* ans=solve (in, post, postorderIndex,0, n-1,n);
        return ans;
}



*/