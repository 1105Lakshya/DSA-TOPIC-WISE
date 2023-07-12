/*

Given a binary tree and a node called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.


Example 1:

Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value 
8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.
Example 2:

Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      7
  /    / 
 8    10
Target Node = 10
Output: 5


*/



/*

class Solution {
    //creates mapping and return target node
    private:
    void createParentMapping(Node* root , unordered_map<Node*, Node* > &nodeToParent, int target, Node* &targetNode){
        if(root==NULL )
        return ;
        
        
        if(root->data==target)
        targetNode=root;
        
        if(root->left!=NULL)
        nodeToParent[root-> left]=root;
        
        if(root->right!=NULL)
        nodeToParent[root-> right]=root;
        
        
        createParentMapping(root->left , nodeToParent , target ,targetNode);
        createParentMapping(root->right , nodeToParent , target ,targetNode);
    }
    
    
    
int  burnTree(Node* root ,unordered_map<Node*, Node* > &nodeToParent){
unordered_map<Node*, bool> visited;
queue<Node*> q;

q.push(root);
visited[root]=true;

int samay=0;

while(!q.empty()){
    
    bool flag=0;
    int size=q.size();
    for(int i=0;i< size; i++){
        //process neighbouring nodes
        Node*front=q.front();
        q.pop();
        
        if(front->left!=NULL  &&  !visited[front->left]){
            flag=1;
            q.push(front->left);
            visited[front->left]=1;
        }
        if(front->right!=NULL  &&  !visited[front->right]){
            flag=1;
            q.push(front->right);
            visited[front->right]=1;
        }
        if(nodeToParent[front]!=NULL  &&  !visited[nodeToParent[front]]){
            flag=1;
            q.push(nodeToParent[front]);
            visited[nodeToParent[front]]=1;
        }
    }  
    
    if(flag)
    samay++;
}
    return samay;
}    
    
    
    
  public:
    int minTime(Node* root, int target) 
    {   
        unordered_map<Node*, Node* >  nodeToParent;
        nodeToParent[root]=NULL;
        Node* targetNode;
        createParentMapping(root ,nodeToParent,target,targetNode);
        
        int samay;
        samay=burnTree(targetNode , nodeToParent);
        
        
        return samay;
        
        
    }
};












*/


