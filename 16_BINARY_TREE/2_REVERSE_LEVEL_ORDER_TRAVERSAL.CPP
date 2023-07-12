// HOMEWORK
#include<bits/stdc++.h>
using namespace std;


class Node{
    public:

    int data;
    Node* left;
    Node* right;
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

//FUNCTION TO CREATE TREE
Node* buildTree(Node* root ){
cout<<"Enter the data :"<<endl; 
int data;
cin>> data;
root=new Node(data);

if(data==-1){
    return NULL;
}

cout<<"Enter the data for inserting in left OF  "<<data<<endl;
root->left =buildTree(root-> left);
cout<<"Enter the data for inserting in the right OF   "<<data<<endl;
root->right=buildTree(root->right);


return root;

}

vector<int> reverseLevelOrder(Node *root)
{
    
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();
        ans.push_back(temp->data);
        
        
        if(temp->right!=NULL)
        q.push(temp->right);
        
        
        if(temp->left!=NULL)
        q.push(temp->left);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}


int main(){
    
    return 0;
}