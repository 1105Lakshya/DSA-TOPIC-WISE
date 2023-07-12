/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */





/***************************SOLUTION**********************************/
/*



class Solution {
    int count(ListNode* head){
        int size=0;
        while(head!=NULL)
        {
            size++;
            head=head->next;
        }
        return size;
    }
    
    
    TreeNode* convert(ListNode* &head ,int n)
    {
        if(head==NULL || n<1)
            return NULL;
        
        TreeNode* left=convert(head,n/2);
        TreeNode* root=new TreeNode(head->val);
        root->left=left;
        head=head->next;
        root->right=convert(head,n-n/2-1);
        
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int size=count(head);
        ListNode* temp=head;
        TreeNode* ans=convert(temp ,size);
        return ans;
    }
};



*/