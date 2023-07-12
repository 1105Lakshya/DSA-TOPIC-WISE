//            INORDER                 PREORDER                POSTORDER
//              LNR                     NLR                     LRN









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

cout<<"Enter the data for inserting in left OF"<<data<<endl;
root->left =buildTree(root-> left);
cout<<"Enter the data for inserting in the right OF "<<data<<endl;
root->right=buildTree(root->right);


return root;

}

void  buildFromLevelOrder(node*  & root){
    queue < node* > q;
    cout<<"Enter data for root "<<endl;
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp =q.front();
        q.pop();

        cout<<"Enter left node for "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1){
            temp->left=new node(leftdata);
            q.push(temp->left);
        }


        cout<<"Enter right node for "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata != -1){
            temp->right=new node(rightdata);
            q.push(temp->right);
        }
    }


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
    buildFromLevelOrder(root);
    levelOrderTraversal(root);
    


    return 0;
}