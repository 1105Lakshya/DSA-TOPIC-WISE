/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };




################################         SOLUTION             #######################################

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
//     findingkey
    BinaryTreeNode<int>* temp=root;
    int pred=-1;
    int succ=-1;
    
    while(temp->data!=key){
        if(temp->data>key){                   ISKA MATLAB TEMP->DATA EK SUCC HO SAKTA HAI TOH SUCC MEI SAVE KRAALIYYA OR LEFT MEI DHUNDNE CHALLE GYEE KEY KOOO
            succ=temp->data;         
            temp=temp->left;
        }
        else{
            pred=temp->data;
            temp=temp->right;
        }
    }

    
//at this point we have found the key 
//now we will be finding max and min element in the correspoinding node tree if they exist then pred and succ will be updated wrna jo uppar hai woii answer
        
if(temp->left!=NULL){
    BinaryTreeNode<int>* pre_node=temp->left;
        while(pre_node->right!=NULL)
            pre_node=pre_node->right;
        
    
    pred=pre_node->data;
    }
if(temp->right!=NULL){
     BinaryTreeNode<int>* succ_node=temp->right;
        while(succ_node->left!=NULL)
            succ_node=succ_node->left;
        
    
    succ=succ_node->data;
    }
        
    return make_pair(pred,succ);
}





***************************************************************/