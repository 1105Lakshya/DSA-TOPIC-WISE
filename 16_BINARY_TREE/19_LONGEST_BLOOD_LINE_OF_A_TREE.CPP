/*


Given a binary tree of size N. Your task is to complete the function sumOfLongRootToLeafPath(), that find the sum of all nodes on the longest path from root to leaf node.
If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.

Example 1:

Input: 
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3    
      /
     6
Output: 13
Explanation:
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3 
      /
     6

The highlighted nodes (4, 2, 1, 6) above are 
part of the longest root to leaf path having
sum = (4 + 2 + 1 + 6) = 13


*/




// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/


//Iterative solution
class Solution
{   private:
    void findpath(Node*root , int n,vector<Node*> vec, vector<Node*> &vec1){
        if(root==NULL)
        return ;
        vec.push_back(root);
        //base case
        if(root -> data == n){
            for(auto it : vec){
                vec1.push_back (it);
            }
            return ;
        }
        if(root->left)
        findpath(root ->left,n ,vec, vec1);
        
        if(root->right)
        findpath(root ->right,n ,vec, vec1);
        
    }
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       vector<Node*> vec;
       vector<Node*> vec1;
       vector<Node*> vec2;
       findpath(root,n1,vec,vec1);
       findpath(root,n2,vec,vec2);
       unordered_set<Node* > set;
       for(int i=0;i< vec1.size();i++){
           set.insert(vec1[i]);
       }
       for(int i=vec2.size()-1;i>=0;i--){
           if(set.find(vec2[i])!=set.end())
           return vec2[i];
       }
       return NULL;
    }
};









//RECURSIVE SOLUTION 
class Solution1
{
    private:
    void solve ( Node* root , pair<int,int> p,pair<int,int> &ans){
        if(root->left==NULL  && root -> right==NULL){
            p.first+=root->data;
            p.second+=1;
            if(ans.second<p.second){
                ans.first=p.first;
                ans.second=p.second;
                
            }
            else if(ans.second==p.second)
            ans.first=max(ans.first, p.first);
            else
            return ;
            
            
            return ;
        }

        pair<int ,int> temp;
        int n1=p.first+=root->data;
        int n2=p.second+=1;
        
        temp={n1,n2};
        
        if(root->left){
        solve(root-> left ,temp , ans);
        }
        
        if(root->right){
        solve(root-> right ,temp , ans);
        }
        
        
    }
    
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
    pair<int , int > p;
    p={0,0};
    pair<int,int>  ans={0,0};
    solve ( root , p,ans);
    return ans.first;
    }
};






class Solution2_BY_BABBAR
{
public:
    
    void solve(Node* root, int sum, int &maxSum, int len, int &maxLen) {
        //base case
        if( root == NULL ) {
            
            if(len > maxLen) 
            {
                maxLen = len;
                maxSum = sum;
            }
            else if(len == maxLen) 
            {
                maxSum = max(sum, maxSum);
            }
            return;
        }
        
        sum = sum + root->data;
        
        solve(root->left, sum, maxSum, len+1, maxLen);
        solve(root->right, sum, maxSum, len+1, maxLen);

    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int len = 0;
        int maxLen = 0;
        
        int sum = 0;
        int maxSum = INT_MIN;
        
        solve(root, sum, maxSum, len, maxLen);
        
        return maxSum;
    }
};
















// { Driver Code Starts.

int main()
{

    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution1 obj;
        int res = obj.sumOfLongRootToLeafPath(root);
        cout << res << "\n";
    }
    return 0;
}  // } Driver Code Ends


