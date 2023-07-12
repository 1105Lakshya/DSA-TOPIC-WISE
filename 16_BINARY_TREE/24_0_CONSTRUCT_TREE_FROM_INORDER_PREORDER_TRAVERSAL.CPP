/*

Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal. 

Example 1:

Input:
N = 4
inorder[] = {1 6 8 7}
preorder[] = {1 6 7 8}
Output: 8 7 6 1
Example 2:

Input:
N = 6
inorder[] = {3 1 4 0 5 2}
preorder[] = {0 1 3 4 2 5}
Output: 3 4 1 5 2 0
Explanation: The tree will look like
       0
    /     \
   1       2
 /   \    /
3    4   5



*/



/*

class Solution{
    private:
    //we can use a map to find the position in constant space 
    void createmapping(int in[], map<int,int> nodeToIndex, int n){
        for(int i=0;i< size;i++){
        nodeToIndex[in[i]]=i;
            
        }
    }


    
    Node* solve(int in[], int pre[], int& index  , int inorderStart ,int inorderEnd , int size){
        //base case 
        if(index>size-1 || inorderStart>inorderEnd)     // dost ye condition rattlee visulaise krne ke liye dry run karlee
        return NULL;
        
        int element=pre[index];
        index++;
        Node* root =new Node(element);
         
        int position_in_inorder=nodeToIndex[element];
        
        
        //recursive call
        root-> left=solve(in , pre , index ,inorderStart, position_in_inorder-1 ,size);
        root-> right=solve(in , pre , index , position_in_inorder+1, inorderEnd, size );
        
        return root;
        
        
        
        
    }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        int preorderIndex=0;
        unordered_map<int ,int > nodeToIndex;

        createmapping(in, nodeToIndex, n);


        Node* ans=solve (in, pre, preorderIndex,0, n-1,n);
        return ans;
    }
};   


*/