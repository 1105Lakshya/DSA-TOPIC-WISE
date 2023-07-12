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






//INSERTION KI TIME COMPLEXITY LOG(n) IN CASE OF A BINARY TREE


Node*  insertIntoBST(Node* root ,int  data){
//base case 
if(root==NULL){
root=new Node(data);
return root;
}

if(data>root->data){
    //right part mei insert karnna haiii
    root->right =insertIntoBST(root->right,data);
}
else{
    //left part mei insert karnaa hai
    root->left=insertIntoBST(root->left , data);
}


return root;
}


void takeInput(Node* & root ){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertIntoBST(root, data);
        cin>>data;
    }
}


//***********************************LEVEL ORDER TRAVERSAL*************************

void levelOrderTraversal(Node* root){
    queue<Node*>  q;
    q.push(root);           
    q.push(NULL);  //pehlii Node ke liyee seprator daal diyyyaaa       

    // NULL separate karregaaa q meii different levels koooo

    while(!q.empty()){
        Node*temp=q.front();
        q.pop();

        if(temp==NULL){   //puranna level complete traverse ho chukkaa haiii
        cout<<endl;               // tohh enter maardiyyyaa
        if(!q.empty()){      //queue still has some child Nodes 
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
    Node* root=NULL;
    cout<<"My lovely deepika data enter karrooo  BST mei enter krnne ke liyyee "<<endl;
    takeInput(root);
    

    cout<<"deepika mella bachha mai BST print karra huu "<<endl;

    levelOrderTraversal(root);
    return 0;
}