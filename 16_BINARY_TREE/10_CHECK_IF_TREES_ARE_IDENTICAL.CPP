#include<bits/stdc++.h>
using namespace std;


/*
Given two binary trees, the task is to find if both of them are identical or not. 


Example 2:

Input:
     1          1
   /   \      /   \
  2     3    2     3
Output: Yes

*/





//Time Complexity: O(N).
// Auxiliary Space: O(Height of the Tree).





/*

class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
    //base case
    if(r1==NULL && r2==NULL)
        return true;
    if(r1==NULL && r2!=NULL)
        return false;
    if(r1!=NULL && r2==NULL)
        return false;
        
    bool present=false;
    if(r1->data==r2->data)
    present=true;
    
    if(present){
    bool left=isIdentical(r1->left, r2->left);
    bool right=isIdentical(r1->right, r2->right);
    
       if(left && right ) 
       return true;
       else
       return false;
    }
    else{
        return false;
    }
    }
};



*/

int main(){
    
    return 0;
}