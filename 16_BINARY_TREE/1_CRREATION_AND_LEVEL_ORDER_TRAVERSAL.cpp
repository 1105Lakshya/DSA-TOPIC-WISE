#include<bits/stdc++.h>
using namespace std;

class node{
    public:

    int data;
    node* left;
    node* right;
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

//FUNCTION TO CREATE TREE
node* buildTree(node* root ){
cout<<"Enter the data :"<<endl;
int data;
cin>> data;
root=new node(data);

if(data==-1){
    return NULL;
}

cout<<"Enter the data for inserting in left OF  "<<data<<endl;
root->left =buildTree(root-> left);
cout<<"Enter the data for inserting in the right OF   "<<data<<endl;
root->right=buildTree(root->right);


return root;

}

//***********************************LEVEL ORDER TRAVERSAL*************************

void levelOrderTraversal(node* root){
    queue<node*>  q;
    q.push(root);           
    q.push(NULL);  //pehlii node ke liyee seprator daal diyyyaaa       

    // NULL separate karregaaa q meii different levels koooo

    while(!q.empty()){
        node*temp=q.front();
        q.pop();

        if(temp==NULL){   //puranna level complete traverse ho chukkaa haiii
        cout<<endl;               // tohh enter maardiyyyaa
        if(!q.empty()){      //queue still has some child nodes 
        q.push(NULL);           //is samaya next level ke sarre present honngge q meii  toh  NULL daal diyya q ke end mei  to separate from the ones that will be entered 

        }
        }
        else{
        cout<<temp->data<<" ";      // agar null ni haii toh jo agge padda q meii uskaa data print kardooo
        if(temp->left  != NULL){
        q.push(temp->left);
        }

        if(temp->right != NULL){
            q.push(temp->right);
        }

        }

    }
}

int main(){
    node* root =NULL;
    //creating a Tree
    root = buildTree(root);

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    //level order traversal
    cout<<"printing the level order traversal output"<<endl;
    levelOrderTraversal(root);
    
    return 0;
}