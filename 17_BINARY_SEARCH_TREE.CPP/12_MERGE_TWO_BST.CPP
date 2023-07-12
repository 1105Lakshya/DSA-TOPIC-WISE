

//APPROACH 1--->CREATE TWO INORDER TRAVERSAL VECTORS THEN MERGGE THEM AND CREATE A TREE FROM INORDER TRAVERSAL OF MERGED ARRAY
/*



void inorder_traversal(TreeNode<int> * root , vector<int> &vect ){
    if(root==NULL)
        return ;
     inorder_traversal(root->left,vect);
     vect.push_back(root->data);
    inorder_traversal(root->right,vect);
    
}
vector<int> merge(vector<int> arr1 ,vector<int> arr2){
    int n=arr1.size();
    int m=arr2.size();
    vector<int> ans(n+m);
    int k=0;
    int i=0;
    int j=0;
    while(i<n  && j<m){
    if(arr1[i]<arr2[j])
     ans[k++]=arr1[i++];    
    else{
        ans[k++]=arr2[j++];
    }
    }
    while(i<n)
        ans[k++]=arr1[i++];
    while(j<n)
        ans[k++]=arr2[j++];
    
    return ans;
    
}
TreeNode<int>*     inorderToBST(int s ,int e , vector<int> vect)
{
    //base case
    if(s>e)
        return NULL;
    
    int mid= (s+e)/2;
    TreeNode<int>* root = new TreeNode<int>(vect[mid]);
    root->left=inorderToBST(s, mid-1 ,vect);
    root->right=inorderToBST(mid+1, e ,vect);
    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    vector<int> vect1;
    vector<int> vect2;
    inorder_traversal(root1, vect1);
    inorder_traversal(root2, vect2);
    vector<int> merged_array= merge(vect1 , vect2);
    
    
    return inorderToBST(0,merged_array.size()-1,merged_array);
    
}

*/

//APPROACH 2-->
// 1. CONVERT THE TWO TREES INTO SORTED LINKED 
// 2. MERGE TWO SORTED LINKED LIST
// 3. CREATE A BST FROM SORTED LINKED LIST

/*
/////////////////convert krna DLL mei toh eash hai chooteee////////////////////////////////////////

void convert_to_DLL(TreeNode<int> *root ,TreeNode<int> *&prev ,TreeNode<int> *&head){
    if(root==NULL)
        return;
    convert_to_DLL(root->left, prev, head);
    if(prev==NULL)
        head=root;
    else{
        prev->right=root;
        root->left=prev;
        
    }
    prev=root;
    convert_to_DLL(root->right, prev ,head);
}


///////////////////////here we merged two linked list//////////////////////////////////////////
TreeNode<int> *  mergeLinkedList(TreeNode<int> *head1 ,TreeNode<int> *head2){
    TreeNode<int> *head=NULL;
    TreeNode<int> *tail=NULL;
    while(head1!=NULL && head2!=NULL){
        if(head1->data <head2->data)
        {
            if(head==NULL)
            {
                head=head1;
                tail=head1;
                head1=head1->right;
            }
            else
            {
               tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;
            }
        }
        else
        {
            if(head==NULL)
            {
                head=head2;
                tail=head2;
                head2=head2->right;
            }
            else
            {
                tail->right=head2;
                head2->left=tail;
                tail=head2;
                head2=head2->right;
            }
        }
    }
    
    
    while(head1!=NULL)
    {
          tail->right=head1;
          head1->left=tail;
          tail=head1;
          head1=head1->right;
    }
    
    while(head2!=NULL)
    {
          tail->right=head2;
          head2->left=tail;
          tail=head2;
          head2=head2->right;    
    }
    return head;
} 



/////////////////here we have counted nodes/////////////////////////////////////////
int countNodes(TreeNode<int> *head){
    int count=1;
    while(head->right!=NULL){
        count++;
        head=head->right;
    }
    return count;
}



//////////////////////////////converting  sorted dLL to BST//////////////////////////////////////
TreeNode<int> *  sortedLLtoBST(TreeNode<int> * & head ,int n){
    //base case 
    if(n<=0 || head==NULL)
        return NULL;
    
    TreeNode<int> * left=sortedLLtoBST(head, n/2);
    TreeNode<int> *root =head;
    root->left =left;
    
    head=head->right;
    root->right =sortedLLtoBST(head , n-n/2-1);
    return root;
}



*/
