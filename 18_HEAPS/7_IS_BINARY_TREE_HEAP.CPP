/*
Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.

Example 1:

Input:
      5
    /  \
   2    3
Output: 1
Explanation: The given tree follows max-heap property since 5,
is root and it is greater than both its children.

Example 2:

Input:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 0

Your Task:
You don't need to read input or print anything. Your task is to complete the function isHeap() which takes the root of Binary Tree as parameter returns True if the given binary tree is a heap else returns False.

Expected Time Complexity: O(N)
Expected Space Complexity: O(N)






*/



/*
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        
        queue<TreeNode*> que;

        que.push(root);

        bool past = false; //kya aapne past me null node dekha hai

        while(!que.empty()){
            TreeNode* node = que.front();
            que.pop();

            if(node == NULL){
                past = true;
            }
            else{
                if(past == true){
                    return false;
                }

                que.push(node -> left);
                que.push(node -> right);
            }
        }
        return true;
    }
};














class Solution {
  private:
  int countNode(struct Node* root){
    if(root==NULL)
    return 0;
    
    return countNode(root->left)+1+countNode(root->right);
}

bool isCBT(struct Node* root ,int index , int cnt ){
    if(root==NULL)
    return true;
    
    if(index>=cnt)          AGAR NODE EXIST KRTII HAIII MAGAR USKKKA INDEX GREATER HAII HEAP KE SIZE SE MATALB COMPLETE BST NI HAII
    return false;                   //REFER IMAGE
    else
    {
        bool left=isCBT(root->left ,2*index+1 ,cnt );            // LEFT PATTA LAGGA LIYYA CBT HAI KE NII
        bool right=isCBT(root->right ,2*index+2 ,cnt );             //RIGHT PATA LAGGA LIYAAA
        
        return (left && right);
    }
    
}



bool isMaxOrder(struct Node* root ){
    //leafNode
    if(root->left ==NULL && root->right ==NULL)          // LEAF NODE MAXORDER HOTI HI HAI
    return true;
    
    if(root->right ==NULL){
        return  (root->data  > root->left ->data);             //COMPLETE BST AGAR RIGHT NULL HAI TOH SIRF LEFT SE COMPARE KIYYA
    }
    else{
        
        if((root->data > root->left->data &&  root->data > root->right->data) && isMaxOrder(root->left) && isMaxOrder(root->right))      //PRESENT NODE CHECCK LEFT SUBTREE CHECK RIGHT SUBTREE CHECK
        return true;
        else
        return false;
    }
}

  public:
    bool isHeap(struct Node* tree) {
    int index=0;
    int totalCount=countNode(tree);
    if(isCBT(tree , index ,totalCount)   && isMaxOrder(tree))           // heap ke liye check kiyya kya complete binarya tree and maxordere property follow krta haiii 
    return true;
    else
    return false;
  
    }
};



*/