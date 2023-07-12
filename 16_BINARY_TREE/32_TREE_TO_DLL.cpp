/*

Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

TreeToList

Example 1:

Input:
      1
    /  \
   3    2
Output:
3 1 2 
2 1 3 
Explanation: DLL would be 3<=>1<=>2
Example 2:

Input:
       10
      /   \
     20   30
   /   \
  40   60
Output:
40 20 60 10 30 
30 10 60 20 40
Explanation:  DLL would be 
40<=>20<=>60<=>10<=>30

*/
//approach 1 using previouse pointere
/*

// This function should return head to the DLL
class Solution
{   private :
    void convert_to_DLL(Node* root , Node*& prev , Node*& head){
        if(root==NULL)
        return ;
        
        convert_to_DLL(root->left , prev , head);
        if(prev==NULL)
        head=root;
        
        else{
            prev->right=root;
            root->left=prev;
        }
        prev=root;
        
        convert_to_DLL(root->right, prev, head);
        
    }
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        Node*head=NULL;
        Node*prev=NULL;
        
        convert_to_DLL(root,prev, head);
        return head;
    }
};



*/


//approach 2 babbar bhaiyyaaa approach

/*

class Solution
{   
    private:
    void convertToDLL(Node* root, Node*& head){
        //base case
        if(root==NULL)
        return ;
        
        convertToDLL(root->right, head);
        root->right=head;
        
        
        if(head!=NULL)
        head->left=root;
        
        head=root;
        convertToDLL(root->left , head);
    }
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
    Node* head=NULL;
    convertToDLL(root ,head);
    head->left=NULL;
    return head;
    }
};



*/