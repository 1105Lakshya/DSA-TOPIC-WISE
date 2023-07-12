/*

Given a binary tree and an integer K. Find the number of paths in the tree which have their sum equal to K.
A path may start from any node and end at any node in the downward direction.


Example 1:

Input:      
Tree = 
          1                               
        /   \                          
       2     3
K = 3
Output: 2
Explanation:
Path 1 : 1 + 2 = 3
Path 2 : only leaf node 3




*/



// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


 // } Driver Code Ends
//User function template for C++

/*
struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/





class Solution{
  private:
    void solve(Node* root , int k , int & count , vector<int > path){
        //base case
        if(root==NULL )
        return ;
        
        
        //cuurrentt path meii na presetn node enter kardooooo
        path.push_back(root->data);
        
        //left ki call
        solve(root -> left ,k , count , path);
        
        // right
        solve(root->right ,k ,count ,path);
        
        
        //checck for k sum
        int size=path.size();
        int sum=0;
        for(int i=size-1;i>=0;i--){
            sum+=path[i];
            if(sum==k){
                count++;
            }
        }
        path.pop_back();
        }  
  public:
    int sumK(Node *root,int k)
    {
    vector<int> path;
    int count=0;
    solve(root, k , count , path);
    return count ;
    }
};

























